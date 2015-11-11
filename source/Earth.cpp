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
#include "EarthSystem.h"
#include "sMesh.h"


#include <SOIL/SOIL.h>

typedef glm::vec4 color4;
typedef glm::vec4 point4;

struct SolarSystem {
  float day = 0.f;

  float days_per_tick = 0.1;
  sls::EarthSystem earth;

  float universe_scaling = 1 / 10000.f;
};

static SolarSystem solar_system;

bool render_line;
sls::sMesh mesh;
GLuint buffer;

GLuint index_buffer;
GLuint vao;


GLuint vPosition, vNormal, vUv;

GLuint program;

// Model-view and projection matrices uniform location
GLuint ModelView, NormalMatrix, Projection;


struct {
  GLuint position, normal, tex_coord;
} attributes;


//==========Trackball Variables==========
static float curquat[4], lastquat[4];
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


//----------------------------------------------------------------------------


// OpenGL initialization
void
init()
{
  mesh = sls::sMesh::make_cube();

  auto verts = mesh.pack_vertices();

  //for (auto const &i: verts) {
  //  fprintf(stderr, "[%f %f %f] [%f %f %f] [%f %f]\n",
  //          i.position.x, i.position.y, i.position.z,
  //          i.normal.x, i.normal.y, i.normal.z,
  //          i.uv.s, i.uv.t);
  //}

  // Create a vertex array object
  glGenVertexArraysAPPLE(1, &vao);
  glBindVertexArrayAPPLE(vao);

  // Create and initialize a buffer object
  glGenBuffers(1, &buffer);
  glGenBuffers(1, &index_buffer);

  glBindBuffer(GL_ARRAY_BUFFER, index_buffer);
  glBufferData(GL_ARRAY_BUFFER, mesh.triangles.size() * sizeof(uint32_t), &mesh.triangles[0], GL_DYNAMIC_DRAW);


  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(sls::Vertex), &verts[0], GL_DYNAMIC_DRAW);

  std::string vshader = source_path + "/shaders/vshading_example.glsl";
  std::string fshader = source_path + "/shaders/fshading_example.glsl";

  program = InitShader(vshader.c_str(), fshader.c_str());
  // Load shaders and use the resulting shader program
  glUseProgram(program);

  // set up vertex arrays
  vPosition = glGetAttribLocation(program, "vPosition");
  glEnableVertexAttribArray(vPosition);

  vNormal = glGetAttribLocation(program, "vNormal");
  glEnableVertexAttribArray(vNormal);

  vUv = glGetAttribLocation(program, "vTexCoord");
  glEnableVertexAttribArray(vUv);

  glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, (void*)offsetof(sls::Vertex, position));
  glVertexAttribPointer(vNormal, 3, GL_FLOAT, GL_FALSE, 0, (void*)offsetof(sls::Vertex, normal));
  glVertexAttribPointer(vUv, 2, GL_FLOAT, GL_FALSE, 0, (void*)offsetof(sls::Vertex, uv));


  // Initialize shader lighting parameters
  point4 light_position(0.0, 0.0, 10.0, 1.0);

  color4 light_ambient(0.1, 0.1, 0.1, 1.0);
  color4 light_diffuse(1.0, 1.0, 1.0, 1.0);
  color4 light_specular(1.0, 1.0, 1.0, 1.0);

  color4 material_ambient(0.1, 0.1, 0.1, 1.0);
  color4 material_diffuse(1.0, 0.8, 0.0, 1.0);
  color4 material_specular(0.0, 0.0, 0.0, 1.0);
  float material_shininess = 1;


  color4 ambient_product = light_ambient * material_ambient;
  color4 diffuse_product = light_diffuse * material_diffuse;
  color4 specular_product = light_specular * material_specular;

  glUniform4fv(glGetUniformLocation(program, "AmbientProduct"), 1, ambient_product);
  glUniform4fv(glGetUniformLocation(program, "DiffuseProduct"), 1, diffuse_product);
  glUniform4fv(glGetUniformLocation(program, "SpecularProduct"), 1, specular_product);
  glUniform4fv(glGetUniformLocation(program, "LightPosition"), 1, light_position);
  glUniform1f(glGetUniformLocation(program, "Shininess"), material_shininess);

  // Retrieve transformation uniform variable locations
  ModelView = glGetUniformLocation(program, "ModelView");
  NormalMatrix = glGetUniformLocation(program, "NormalMatrix");
  Projection = glGetUniformLocation(program, "Projection");

  glEnable(GL_DEPTH_TEST);

  glShadeModel(GL_SMOOTH);

  glClearColor(0.8, 0.8, 1.0, 1.0);

  scaling = 0;
  moving = 0;
  panning = 0;
  beginx = 0;
  beginy = 0;

  matident(curmat);
  trackball(curquat, 0.0f, 0.0f, 0.0f, 0.0f);
  trackball(lastquat, 0.0f, 0.0f, 0.0f, 0.0f);
  add_quats(lastquat, curquat, curquat);
  build_rotmatrix(curmat, curquat);

  scalefactor = 1.0;
  render_line = false;


  //---setup solar system


}

//----------------------------------------------------------------------------

void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //  Generate tha model-view matrixn

  glUseProgram(program);

  const vec3 viewer_pos(0.0, 0.0, 3.0);
  mat4 track_ball = mat4(curmat[0][0], curmat[1][0], curmat[2][0], curmat[3][0],
                         curmat[0][1], curmat[1][1], curmat[2][1], curmat[3][1],
                         curmat[0][2], curmat[1][2], curmat[2][2], curmat[3][2],
                         curmat[0][3], curmat[1][3], curmat[2][3], curmat[3][3]);


  mat4 model_view = Translate(-viewer_pos) *              //Move Camera Back
                    Translate(ortho_x, ortho_y, 0.0) *      //Pan Camera
                    track_ball *                            //Rotate Camera
                    Scale(scalefactor, scalefactor, scalefactor);  //User Scale



  glBindVertexArrayAPPLE(vao);

  glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);
  glUniformMatrix4fv(NormalMatrix, 1, GL_TRUE, transpose(invert(model_view)));

  GLsizei n_elements = GLsizei(mesh.triangles.size() - mesh.triangles.size() % 3);

  glDrawElements(GL_TRIANGLES, (GLsizei)mesh.triangles.size(), GL_UNSIGNED_INT, 0);


  glBindVertexArrayAPPLE(0);
  glutSwapBuffers();
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
void mouse(GLint button, GLint state, GLint x, GLint y)
{

  if (state == GLUT_UP) {
    moving = scaling = panning = 0;
    glutPostRedisplay();
    return;
  }

  if (glutGetModifiers() & GLUT_ACTIVE_SHIFT) {
    scaling = 1;
  } else if (glutGetModifiers() & GLUT_ACTIVE_ALT) {
    panning = 1;
  } else {
    moving = 1;
    trackball(lastquat, 0, 0, 0, 0);
  }

  beginx = x;
  beginy = y;
  glutPostRedisplay();
}


/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
void motion(GLint x, GLint y)
{

  int W = glutGet(GLUT_WINDOW_WIDTH);
  int H = glutGet(GLUT_WINDOW_HEIGHT);

  float dx = (beginx - x) / (float) W;
  float dy = (y - beginy) / (float) H;

  if (panning) {
    ortho_x += dx;
    ortho_y += dy;

    beginx = x;
    beginy = y;
    glutPostRedisplay();
    return;
  }
  else if (scaling) {
    scalefactor *= (0.5f + dx);

    beginx = x;
    beginy = y;
    glutPostRedisplay();
    return;
  }
  else if (moving) {
    trackball(lastquat,
              (2.0f * beginx - W) / W,
              (H - 2.0f * beginy) / H,
              (2.0f * x - W) / W,
              (H - 2.0f * y) / H
    );

    add_quats(lastquat, curquat, curquat);
    build_rotmatrix(curmat, curquat);

    beginx = x;
    beginy = y;
    glutPostRedisplay();
    return;
  }
}

//----------------------------------------------------------------------------
void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 033: // Escape Key
    case 'q':
    case 'Q':
      exit(EXIT_SUCCESS);
      break;
    case ' ':
      render_line = !render_line;
      if (render_line) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      }
      break;
  }
}

//----------------------------------------------------------------------------
void reshape(int width, int height)
{
  glViewport(0, 0, width, height);

  GLfloat aspect = GLfloat(width) / height;
  mat4 projection = Perspective(45.0, aspect, 0.5, 5.0);

  glUniformMatrix4fv(Projection, 1, GL_TRUE, projection);
}

//----------------------------------------------------------------------------
void timer(int value)
{

  using namespace glm;
  glutTimerFunc(33, timer, 1);

  solar_system.day += solar_system.days_per_tick;

  //fprintf(stderr, "\nsolar system log: day %f\n", solar_system.day);

  auto sun = glm::vec4(solar_system.earth.get_solar_position(solar_system.day), 1.0);
  ///fprintf(stderr, "sun position [%f %f %f]\n\n", sun.x, sun.y, sun.z);

  glUniform4fv(glGetUniformLocation(program, "LightPosition"), 1, (float *) &sun);

  glutPostRedisplay();
}


//----------------------------------------------------------------------------
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(512, 512);
  glutCreateWindow("Tulane Earth");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);

  timer(1);

  glutMainLoop();
  return 0;
}
