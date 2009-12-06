#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class ImageManager
{
	public:
		/* 
		 * Basically just initializes our map
		 */
		ImageManager(){}

		/*
		 * Clears out the map and deletes any iamges
		 */
		 ~ImageManager();

		/*
		 * Loads an image into the map
		 * @param name: the unique name of the string being stored
		 * @param filename: the path to the iamge we want to store
		 * @return: the iamge you just created
		 */
		sf::Image AddImage(std::string name, std::string filename);

		/*
		 * Searches the map for an image with the specified name
		 * @param name: A name identifying the desired image
		 * @return: the image you asked for
		 */
		sf::Image GetImage(std::string name);

		/*
		 * Removes an image from the map
		 * @param name: A name identifying the desired image
		 */
		 void RemoveImage(std::string name);

	private:
		// A map of images and a string identifier
		// to let us only load images into memory once
		map<string, sf::Image*> imageMap_;

		// instead of having to redeclare this thing
		// I'm going to be lazy and make it a member variable.
		map<string, sf::Image*>::iterator it_;
};
