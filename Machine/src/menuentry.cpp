#include "menuentry.hpp"

MenuEntry::MenuEntry(int id, std::string text)
: id_(id), text_(text, sf::Font::GetDefaultFont(), 16), selected_(false)
{
}

void MenuEntry::Draw(sf::RenderWindow *window, int x, int y, int width, int height)
{
	int center_x = (x + width / 2) - (text_.GetRect().GetWidth() / 2);
	int center_y = (y + height / 2) - (text_.GetRect().GetHeight() / 2);
	text_.SetPosition(center_x, center_y);

	sf::Color bg = sf::Color(0, 0, 0);
	sf::Color border = sf::Color(255, 255, 255);
	sf::Color fg = sf::Color(255, 255, 255);

	if (selected_)
	{
		bg = sf::Color(255, 255, 255);
		border = sf::Color(0, 0, 0);
		fg = sf::Color(0, 0, 0);
	}

	text_.SetColor(fg);

	window->Draw(sf::Shape::Rectangle(x, y, x + width, y + height, bg, 2.0f, border));
	window->Draw(text_);
}
