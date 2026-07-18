#version 330

// Must match the `out` names in your paired vertex shader exactly --
// these are varyings between your own two shader stages, raylib doesn't
// fix these names (unlike attributes/uniforms coming from the mesh/material).
in vec3 fragNormal;
in vec3 fragPosition;

// Custom uniforms -- no raylib default for lighting, you own these fully.
uniform vec3 lightPos;
uniform vec3 lightColor;

// Was `objectColor` (vec3, manually set every frame). Renamed to colDiffuse
// (vec4) so rlgl fills it automatically from the material's tint -- one
// less uniform you have to fetch/set yourself in C++.
uniform vec4 colDiffuse;

uniform sampler2D texture0;

out vec4 finalColor;

void main()
{
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
 
    // diffuse
    vec3 norm = normalize(fragNormal);
    vec3 lightDir = normalize(lightPos - fragPosition);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
 
    // texture0 is a sampler2D (a texture-unit handle), not a color --
    // you have to sample it at a UV coordinate to get an actual vec4 out.
    vec4 texelColor = texture(texture0, fragTexCoord);
 
    vec3 result = (ambient + diffuse) * colDiffuse.rgb * texelColor.rgb;
    finalColor = vec4(result, colDiffuse.a * texelColor.a);
}