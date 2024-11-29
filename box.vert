#version 330

uniform mat4 uPMatrix, uVMatrix, uMMatrix;
uniform vec3 uLightLocation, uCamera;

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTextureCoord;
layout (location = 2) in vec3 aNormal;

smooth out vec2 vTextureCood;
smooth out vec4 vAmbient;
smooth out vec4 vDiffuse;
smooth out vec4 vSpecular;

void pointLight(
    vec3 fragPosition,
    vec3 normal,
    inout vec3 outAmbient,
    inout vec3 outDiffuse,
    inout vec3 outSpecular,
    vec3 lightAmbient,
    vec3 lightDiffuse,
    vec3 lightSpecular,
    float shininess)
{
    outAmbient = lightAmbient;

    vec3 normalTarget = fragPosition + normal;
    vec3 newNormal = normalize((uMMatrix * vec4(normal, 0.0)).xyz);
    vec3 eye = normalize(uCamera - (uMMatrix * vec4(fragPosition, 1.0)).xyz);
    vec3 vp = normalize(uLightLocation - (uMMatrix * vec4(fragPosition, 1.0)).xyz);
    vec3 halfVector = normalize(eye + vp);

    float nDotViewPotision = max(0.0, dot(newNormal, vp));
    outDiffuse = lightDiffuse * nDotViewPotision;

    float nDotViewHalfVector = dot(newNormal, halfVector);
    float powerFactor = max(0.0, pow(nDotViewHalfVector, shininess));
    outSpecular = lightSpecular * powerFactor;
}

void main(void)
{
    gl_Position = uPMatrix * uVMatrix * uMMatrix * vec4(aPosition, 1.0);

    vec3 ambient, diffuse, specular;
    vec3 lightAmbient = vec3(0.6, 0.6, 0.6);
    vec3 lightDiffuse = vec3(0.8, 0.8, 0.8);
    vec3 lightSpecular = vec3(0.9, 0.9, 0.9);
    float shininess = 16.0;

    vec3 fragPosition = (uMMatrix * vec4(aPosition, 1.0)).xyz;
    vec3 transformedNormal = normalize(mat3(transpose(inverse(uMMatrix))) * aNormal);

    pointLight(fragPosition, transformedNormal, ambient, diffuse, specular, lightAmbient, lightDiffuse, lightSpecular, shininess);

    vAmbient = vec4(ambient, 1.0);
    vDiffuse = vec4(diffuse, 1.0);
    vSpecular = vec4(specular, 1.0);
    vTextureCood = aTextureCoord;
}
