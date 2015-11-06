attribute  vec4 vPosition;
attribute  vec3 vNormal;

uniform mat4 ModelView;
uniform mat4 Projection;
uniform mat4 NormalMatrix;

varying vec2 texCoord;
varying vec3 pos;
varying vec3 N;


void main()
{
    // Transform vertex  position into eye coordinates
    pos = (ModelView * vPosition).xyz;
    
    // Transform vertex normal into eye coordinates
    vec4 Nt = NormalMatrix*vec4(vNormal, 0.0);
    N  = normalize(Nt.xyz);


    gl_Position = Projection * ModelView * vPosition;

}
