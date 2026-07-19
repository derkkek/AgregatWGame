#version 330

in vec3 fragNormal;
in vec3 fragPosition;
in vec2 fragTexCoord;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec4 colDiffuse;
uniform sampler2D texture0;

out vec4 FragColor;

uniform vec3 viewPos;

vec3 BlinnPhong(vec3 normal, vec3 fragPos, vec3 lightPos, vec3 lightColor)
{
    // diffuse
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;
    // specular
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
    vec3 specular = spec * lightColor;    
    // simple attenuation
    float max_distance = 1.5;
    float distance = length(lightPos - fragPos);
    float attenuation = 1.0 / (distance);
    
    diffuse *= attenuation;
    specular *= attenuation;
    
    return diffuse + specular;
}


void main()
{
    vec3 color = texture(texture0, fragTexCoord).rgb;

    vec3 lighting = BlinnPhong(fragNormal, fragPosition, lightPos, vec3(1,1,1));

    color *= lighting;
    color = pow(color, vec3(1.0 / 2.2));
    FragColor = vec4(color, 1.0);
}