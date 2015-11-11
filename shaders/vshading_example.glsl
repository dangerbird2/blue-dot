attribute  vec3 vPosition;
attribute  vec3 vNormal;
attribute  vec2 vTexCoord;

uniform mat4 ModelViewEarth;
uniform mat4 Projection;
uniform mat4 NormalMatrix;

varying vec2 texCoord;
varying vec3 pos;
varying vec3 N;
varying vec2 texCoord;


void main()
{
    texCoord    = vTexCoord;

    // Transform vertex  position into eye coordinates

    pos = (ModelView * vec4(vPosition, 1.0)).xyz;

    // Transform vertex normal into eye coordinates
    vec4 Nt = NormalMatrix*vec4(vNormal, 0.0);
    N  = normalize(Nt.xyz);



    gl_Position = Projection * ModelView * vec4(vPosition, 1.0);

}
