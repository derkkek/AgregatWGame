#version 330

// No explicit layout(location=N) -- use raylib's default attribute NAMES
// instead and let LoadShader bind them to the correct locations itself.
in vec3 vertexPosition;
in vec3 vertexNormal;

// mvp/matModel/matNormal are auto-set every DrawModel() call by rlgl --
// no need to multiply projection*view*model yourself, mvp is already that
// product, precomputed once per draw instead of once per vertex.
uniform mat4 mvp;
uniform mat4 matModel;
uniform mat4 matNormal;

out vec3 fragPosition;
out vec3 fragNormal;

void main()
{
    fragPosition = vec3(matModel * vec4(vertexPosition, 1.0));

    // normalize + transform by the normal matrix, not a bare pass-through --
    // the original code's `Normal = aNormal` only works for uniform scale,
    // and breaks under any non-uniform scale on the model matrix.
    fragNormal = normalize(mat3(matNormal) * vertexNormal);

    gl_Position = mvp * vec4(vertexPosition, 1.0);
}
