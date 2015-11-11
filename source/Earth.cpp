//
//  Display a rotating cube with lighting
//
//  Light and material properties are sent to the shader as uniform
//    variables.  Vertex positions and normals are sent after each
//    rotation.

#include "Angel.h"
#include "SourcePath.h"
#include "Trackball.h"
#include "ObjMesh.h"
#include "FreeImage.h"


typedef Angel::vec4  color4;
typedef Angel::vec4  point4;

bool render_line;
Mesh mesh;
GLuint buffer;

// Texture objects and storage for texture image
GLuint month_texture[1];
//GLuint night_texture;

GLuint vPosition, vNormal, vTexCoord;

GLuint program;

// Model-view and projection matrices uniform location
GLuint  ModelViewEarth, ModelViewLight, NormalMatrix, Projection;


//==========Trackball Variables==========
static float curquat[4],lastquat[4];
/* current transformation matrix */
static float curmat[4][4];
mat4 curmat_a;
/* actual operation  */
static int scaling;
static int moving;
static int panning;
/* starting "moving" coordinates */
static int beginx, beginy;
/* ortho */
float ortho_x, ortho_y;
/* current scale factor */
static float scalefactor;


/* -------------------------------------------------------------------------- */
void loadFreeImageTexture(const char* lpszPathName, GLuint textureID){
  
  FreeImage_Initialise();
  
  int X,Y;
  uint8_t *Dst, *Src;
  FIBITMAP*         bitmap=0;
  BITMAPINFO*       info=0;
  FREE_IMAGE_FORMAT fif;
  BYTE*             bits=0;
  int               width,height,bpp,pitch;
  FREE_IMAGE_TYPE   format;
  
  fif = FreeImage_GetFileType(lpszPathName, 0);
  if(fif == FIF_UNKNOWN) {fif = FreeImage_GetFIFFromFilename(lpszPathName);}
  if(fif == FIF_UNKNOWN || !FreeImage_FIFSupportsReading(fif) || !(bitmap = FreeImage_Load(fif, lpszPathName, 0))){
    std::cout << "FreeImage: Unknown image type\n";
  }
  
  info   = FreeImage_GetInfo(bitmap);
  bits   = FreeImage_GetBits      (bitmap);
  width  = FreeImage_GetWidth     (bitmap);
  height = FreeImage_GetHeight    (bitmap);
  bpp    = FreeImage_GetBPP       (bitmap);
  pitch  = FreeImage_GetPitch     (bitmap);
  format = FreeImage_GetImageType (bitmap);
  
  //handle only supported FreeImage
  if((bits == 0) || (width == 0) || (height == 0) || (format!=FIT_BITMAP && format != FIT_UINT16)){
    FreeImage_Unload(bitmap);
    std::cout << "FreeImage: Cannot load image file\n";
  }
  
  GLint GL_format = GL_RGB;
  
  //handle only GRAY, RGB and RGBA
  if (bpp!=8 && bpp!=24 && bpp!=32){
    FreeImage_Unload(bitmap);
    std::cout << "FreeImage: Only supports GRAY, RGB and RGBA\n";
  }else{
    switch(bpp){
      case 8:
        GL_format = GL_LUMINANCE;
        break;
      case 24:
        GL_format = GL_RGB;
        break;
      case 32:
        GL_format = GL_RGBA;
        break;
    }
  }
  
  std::cout << "Image " << lpszPathName << ": " << width << " X " << height << ": " << bpp << " bits\n";
  
  int buffersize  =width*height*(bpp/8);
  uint8_t *buffer = new uint8_t[buffersize];
  
  //fill the buffers
  int step = bpp/8;
  Dst = (uint8_t *)buffer;
  int pixel = 0;
  
  for (Y=height-1;Y>=0;Y--)
    {
    Src=bits+pitch*Y;
    
    for (X=0;X<width;X++,Src+=step,Dst+=(bpp/8),pixel++)
      {
      if (bpp==8)
        {
        Dst[0]=Src[0];
        }
      else
        {Dst[0]=Src[FI_RGBA_RED];Dst[1]=Src[FI_RGBA_GREEN];Dst[2]=Src[FI_RGBA_BLUE];
          if (bpp==32){ Dst[3]=Src[FI_RGBA_ALPHA]; }
        }
      }
    }
  
  glBindTexture( GL_TEXTURE_2D, textureID );
  glTexImage2D( GL_TEXTURE_2D, 0, GL_format, width, height, 0, GL_format, GL_UNSIGNED_BYTE, buffer );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
  
  //Put things away and free memory
  glBindTexture(GL_TEXTURE_2D, 0);
  delete[] buffer;
  FreeImage_Unload(bitmap);
  FreeImage_DeInitialise();
  
}

/* -------------------------------------------------------------------------- */
void
init(){
  //ASSIGNMENT: Make this function make a sphere with triangles, vertices, and texture coordinates
  mesh.makeParametricSphere(64);
  
  //ASSIGNMENT: load and enable textures

  
  // Create a vertex array object
  GLuint vao;
  glGenVertexArraysAPPLE( 1, &vao );
  glBindVertexArrayAPPLE( vao );
  
  // Create and initialize a buffer object
  glGenBuffers( 1, &buffer);
  
  glBindBuffer( GL_ARRAY_BUFFER, buffer );
  unsigned int vertices_bytes = mesh.vertices.size()*sizeof(vec4);
  unsigned int normals_bytes  = mesh.normals.size()*sizeof(vec3);
  unsigned int uv_bytes =  mesh.uvs.size()*sizeof(vec2);
  
  glBufferData( GL_ARRAY_BUFFER, vertices_bytes + normals_bytes + uv_bytes, NULL, GL_STATIC_DRAW );
  unsigned int offset = 0;
  glBufferSubData( GL_ARRAY_BUFFER, offset, vertices_bytes, &mesh.vertices[0] );
  offset += vertices_bytes;
  glBufferSubData( GL_ARRAY_BUFFER, offset, normals_bytes,  &mesh.normals[0] );
  offset += normals_bytes;
  glBufferSubData( GL_ARRAY_BUFFER, offset, uv_bytes,  &mesh.uvs[0] );

  std::string vshader = source_path + "/shaders/vshading_example.glsl";
  std::string fshader = source_path + "/shaders/fshading_example.glsl";
  
  program = InitShader(vshader.c_str(), fshader.c_str());
  // Load shaders and use the resulting shader program
  glUseProgram( program );
  
  // set up vertex arrays
  vPosition = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray( vPosition );
  
  vNormal = glGetAttribLocation( program, "vNormal" );
  glEnableVertexAttribArray( vNormal );
  
  vTexCoord = glGetAttribLocation( program, "vTexCoord" );
  glEnableVertexAttribArray( vTexCoord );

  
  // Initialize shader lighting parameters
  point4 light_position( 0.0, 0.0, 10.0, 1.0 );
  
  color4 light_ambient(  1.0, 1.0, 1.0, 1.0 );
  color4 light_diffuse(  1.0, 1.0, 1.0, 1.0 );
  color4 light_specular( 1.0, 1.0, 1.0, 1.0 ); 
  
  color4 material_ambient( 0.0, 0.0, 0.0, 1.0 );
  color4 material_diffuse( 1.0, 0.8, 0.0, 1.0 );
  color4 material_specular( 0.0, 0.0, 0.0, 1.0 );
  float  material_shininess = 1;
  
  
  color4 ambient_product  = light_ambient * material_ambient;
  color4 diffuse_product  = light_diffuse * material_diffuse;
  color4 specular_product = light_specular * material_specular;
  
  glUniform4fv( glGetUniformLocation(program, "AmbientProduct"), 1, ambient_product );
  glUniform4fv( glGetUniformLocation(program, "DiffuseProduct"), 1, diffuse_product );
  glUniform4fv( glGetUniformLocation(program, "SpecularProduct"), 1, specular_product );
  glUniform4fv( glGetUniformLocation(program, "LightPosition"), 1, light_position );
  glUniform1f(  glGetUniformLocation(program, "Shininess"), material_shininess );
  
  // Retrieve transformation uniform variable locations
  ModelViewEarth = glGetUniformLocation( program, "ModelViewEarth" );
  ModelViewLight = glGetUniformLocation( program, "ModelViewLight" );
  NormalMatrix = glGetUniformLocation( program, "NormalMatrix" );
  Projection = glGetUniformLocation( program, "Projection" );
  
  glUniform1i( glGetUniformLocation(program, "texture0"), 0 );
  glUniform1i( glGetUniformLocation(program, "texture1"), 1 );
  
  glEnable( GL_DEPTH_TEST );
  
  glShadeModel(GL_SMOOTH);

  glClearColor( 0.8, 0.8, 1.0, 1.0 );
  
  scaling  = 0;
  moving   = 0;
  panning  = 0;
  beginx   = 0;
  beginy   = 0;
  
  matident(curmat);
  trackball(curquat , 0.0f, 0.0f, 0.0f, 0.0f);
  trackball(lastquat, 0.0f, 0.0f, 0.0f, 0.0f);
  add_quats(lastquat, curquat, curquat);
  build_rotmatrix(curmat, curquat);
  
  scalefactor = 1.0;
  render_line = false;
}

//----------------------------------------------------------------------------

void
display( void )
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  //  Generate tha model-view matrixn
  
  glUseProgram( program );
  
  const vec3 viewer_pos( 0.0, 0.0, 3.0 );
  mat4 track_ball =  mat4(curmat[0][0], curmat[1][0], curmat[2][0], curmat[3][0],
                          curmat[0][1], curmat[1][1], curmat[2][1], curmat[3][1],
                          curmat[0][2], curmat[1][2], curmat[2][2], curmat[3][2],
                          curmat[0][3], curmat[1][3], curmat[2][3], curmat[3][3]);
  
  
  mat4 model_view = Translate( -viewer_pos ) *              //Move Camera Back
                    Translate(ortho_x, ortho_y, 0.0) *      //Pan Camera
                    track_ball *                            //Rotate Camera
                    Scale(scalefactor,scalefactor,scalefactor);  //Scale
  
  
  glBindBuffer( GL_ARRAY_BUFFER, buffer );
  glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
  glVertexAttribPointer( vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(mesh.vertices.size()*sizeof(vec4)) );
  glVertexAttribPointer( vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(mesh.vertices.size()*sizeof(vec4)+ mesh.normals.size()*sizeof(vec3)) );

  glUniformMatrix4fv( ModelViewEarth, 1, GL_TRUE, model_view);
  glUniformMatrix4fv( ModelViewLight, 1, GL_TRUE, model_view);

  glUniformMatrix4fv( NormalMatrix, 1, GL_TRUE, transpose(invert(model_view)) );

  glPointSize(5);
  glDrawArrays( GL_QUADS, 0, mesh.vertices.size() );

  
  glutSwapBuffers();
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
void mouse(GLint button, GLint state, GLint x, GLint y){
  
  if (state==GLUT_UP){
    moving=scaling=panning=0;
    glutPostRedisplay();
    return;
  }
  
  if( glutGetModifiers() & GLUT_ACTIVE_SHIFT){
    scaling=1;
  }else if( glutGetModifiers() & GLUT_ACTIVE_ALT ){
    panning=1;
  }else{
    moving=1;
    trackball(lastquat, 0, 0, 0, 0);
  }
  
  beginx = x; beginy = y;
  glutPostRedisplay();
}


/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
void motion(GLint x, GLint y){
  
  int W=glutGet(GLUT_WINDOW_WIDTH );
  int H=glutGet(GLUT_WINDOW_HEIGHT);
  
  float dx=(beginx-x)/(float)W;
  float dy=(y-beginy)/(float)H;
  
  if (panning)
    {
    ortho_x  +=dx;
    ortho_y  +=dy;
    
    beginx = x; beginy = y;
    glutPostRedisplay();
    return;
    }
  else if (scaling)
    {
    scalefactor *= (1.0f+dx);
    
    beginx = x;beginy = y;
    glutPostRedisplay();
    return;
    }
  else if (moving)
    {
    trackball(lastquat,
              (2.0f * beginx - W) / W,
              (H - 2.0f * beginy) / H,
              (2.0f * x - W) / W,
              (H - 2.0f * y) / H
              );
    
    add_quats(lastquat, curquat, curquat);
    build_rotmatrix(curmat, curquat);
    
    beginx = x;beginy = y;
    glutPostRedisplay();
    return;
    }
}

//----------------------------------------------------------------------------
void keyboard( unsigned char key, int x, int y ){
  switch( key ) {
    case 033: // Escape Key
    case 'q': case 'Q':
      exit( EXIT_SUCCESS );
      break;
    case ' ':
      render_line = !render_line;
      if(render_line){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      }
     break;
  }
}

//----------------------------------------------------------------------------
void reshape( int width, int height ){
  glViewport( 0, 0, width, height );
  
  GLfloat aspect = GLfloat(width)/height;
  mat4  projection = Perspective( 45.0, aspect, 0.5, 5.0 );
  
  glUniformMatrix4fv( Projection, 1, GL_TRUE, projection );
}

//----------------------------------------------------------------------------
void timer(int value){
  glutTimerFunc(33,timer,1);
    
  glutPostRedisplay();
}


//----------------------------------------------------------------------------
int main( int argc, char **argv ){
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
  glutInitWindowSize( 512, 512 );
  glutCreateWindow( "Tulane Earth" );
  init();
  glutDisplayFunc( display );
  glutKeyboardFunc( keyboard );
  glutReshapeFunc( reshape );
  glutMouseFunc( mouse );
  glutMotionFunc( motion );
  
  timer(1);
  
  glutMainLoop();
  return 0;
}
