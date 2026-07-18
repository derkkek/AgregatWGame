#version 330

in vec3 fragNormal;
in vec3 fragPosition;
in vec2 fragTexCoord;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec4 colDiffuse;
uniform sampler2D texture0;

out vec4 finalColor;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(fragNormal);
    vec3 lightDir = normalize(lightPos - fragPosition);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec4 texelColor = texture(texture0, fragTexCoord);

    vec3 result = (ambient + diffuse) * colDiffuse.rgb * texelColor.rgb;
    finalColor = vec4(result, colDiffuse.a * texelColor.a);
}