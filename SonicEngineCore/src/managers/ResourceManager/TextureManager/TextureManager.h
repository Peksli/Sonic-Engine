
#include <unordered_map>



namespace Sonic
{

	class TextureManager
	{
	public:
		TextureManager() = default;
		virtual ~TextureManager() = default;

		using textureName = std::string;
		using texturePath = std::string;

	private:
		std::unordered_map<textureName, texturePath> um_textures_paths;
	};

}