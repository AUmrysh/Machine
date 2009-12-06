#include "imagemanager.hpp"

ImageManager::~ImageManager()
{
	// Loop through the map, removing each pointer.
	// I believe expected behavior is that the map is removed
	// however pointers will continue to live is they're not explicitly
	// cleaned
	for(it_ = imageMap_.begin(); it_ < imageMap_.end(); it_++)
	{
		delete *it_;
	}

	// clear the map for good measure
	imageMap_.clear();
}

sf::Image* ImageManager::AddImage(std::string name, std::string filename)
{
	// we need a pointer to outlast this functions scope
	sf::Image* temp = new(std::nothrow) sf::Image();

	// attempt to load the file
	if( !temp.LoadFromFile(filename))
	{
		std::cout << "Could not load file: " << filename << endl;
	}
	else
	{
		std::cout << "Image loaded sucessfully from: " << filename << endl;
	}

	// add our new image to the map
	imageMap_[name] = temp;

	return temp;
}

sf::Image* ImageManager::GetImage(std::string name)
{
	it = imageMap_.find(name);

	if( it == imageMap_.end() )
	{
		std::cout << "Could not find image associated with: "
	}

	return *it;
}

void ImageManager::RemoveImage(std::string name)
{
	imageMap_.remove(name);
}
