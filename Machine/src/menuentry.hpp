#ifndef MENUENTRY_HPP
#define MENUENTRY_HPP

#include <string>
#include <SFML/Graphics.hpp>

class MenuEntry
{
	public:
		MenuEntry(int id, std::string text);

		void Draw(sf::RenderWindow *window, int x, int y, int width, int height);

		void set_selected(bool value)
		{
			int color = (value) ? 255 : 0;
			text_.SetColor(sf::Color(color, color, color));
			selected_ = value;
		}

		int get_id() const { return id_; }
				
	private:
		int id_;
		sf::String text_;
		bool selected_;
};

#endif /* MENUENTRY_HPP */
