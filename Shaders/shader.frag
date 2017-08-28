


#version 330 core
in vec2 TexCoord;
in vec4 ourColour;

out vec4 color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

uniform float myUniform;

void main()
{
    vec4 texColour = texture(ourTexture1, TexCoord);// * vec4(ourColour, 1.0f);
	if(texColour.a < 0.1)
		discard;
	color = texColour;
		
	//color  = texture2D(ourTexture2, TexCoord);
}



/*
#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color1;
out vec4 color2;

// Texture samplers
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
	// Linearly interpolate between both textures (second texture is only slightly combined)
	color1 = texture(ourTexture1, TexCoord);//* vec4(ourColor, 0.0f);
	color2 = texture(ourTexture2, TexCoord);//* vec4(ourColor, 0.0f);
	//08081010337http://67.media.tumblr.com/1aa9d686a9a6cc106dc70c43813eae70/tumblr_o33066QylE1qzfyxjo1_1280.jpg
}*/

