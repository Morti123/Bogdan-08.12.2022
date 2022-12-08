#include <SFML/Graphics.hpp>
#include "Header.h"
using namespace sf;
int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(w_width, w_height), w_title);
	window.setFramerateLimit(60);
	CircleShape circle;
	circle.setRadius(r);
	circle.setFillColor(Circle_Color);
	circle.setPosition((w_width - 2 * r) / 2, (w_height - 2 * r) / 2);
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) { circle.move(0, -5); }
	 if (Keyboard::isKeyPressed(Keyboard::Down)) { circle.move(0, 5); }
	 if (Keyboard::isKeyPressed(Keyboard::Left)) { circle.move(-5, 0); }
	 if (Keyboard::isKeyPressed(Keyboard::Right)) { circle.move(5, 0); }
		if (circle.getPosition().y <= 0) {
			circle.setPosition(circle.getPosition().x,0.f);
		}
		if (circle.getPosition().x <= 0) {
			circle.setPosition(0.f, circle.getPosition().y);
		}
		if (circle.getPosition().y >= w_height-2*r) {
			circle.setPosition(circle.getPosition().x, w_height-2*r);
		}
		if (circle.getPosition().x >= w_width-2*r) {
			circle.setPosition(w_width-2*r, circle.getPosition().y);
		}
		window.clear(Color::Blue);
		// ��������� ���� 
		window.draw(circle);
		window.display();

	}

	return 0;
}