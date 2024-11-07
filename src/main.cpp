#include "DisplayManager.hpp"
#include <iostream>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	DisplayManager displayManager("ItIsNotAGame");
	displayManager.run();
	return 0;
}


// di chuyển chuột 

//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Mouse Hover Event");
//    sf::RectangleShape button(sf::Vector2f(100, 50));
//    button.setPosition(350, 275);
//    button.setFillColor(sf::Color::Blue);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//        sf::FloatRect buttonBounds = button.getGlobalBounds();
//
//        if (buttonBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
//            button.setFillColor(sf::Color::Red); // Đổi màu khi di chuột vào button
//        }
//        else {
//            button.setFillColor(sf::Color::Blue); // Trở lại màu ban đầu khi không di chuột vào button
//        }
//
//        window.clear();
//        window.draw(button);
//        window.display();
//    }
//
//    return 0;
//}

//#include <SFML/System.hpp>
//#include <iostream>
//
//int main() {
//    // Tạo một đối tượng sf::Clock để bắt đầu đếm thời gian
//    sf::Clock clock;
//
//    // Đợi một khoảng thời gian
//    sf::sleep(sf::seconds(3));
//
//    // Lấy thời gian đã trôi qua
//    sf::Time elapsed = clock.getElapsedTime();
//
//    // In ra thời gian đã trôi qua dưới dạng giây
//    std::cout << "Elapsed time: " << elapsed.asSeconds() << " seconds" << std::endl;
//
//    return 0;
//}

//#include <SFML/System.hpp>
//#include <iostream>
//
//int main() {
//    // 4s 33k 34k 35k
//    int i = 0;
//    // Một vòng lặp giả lập công việc đang được thực hiện
//        sf::Clock clock; // Bắt đầu đếm thời gian
//    while (clock.getElapsedTime().asSeconds() < 3) {
//        // Làm gì đó trong vòng lặp
//        std::cout << i++ << std::endl;
//    }
//    std::cout << std::endl;
//
//    
//
//    sf::Time elapsed = clock.getElapsedTime(); // Lấy thời gian đã trôi qua
//    std::cout << "Elapsed time: " << elapsed.asSeconds() << " seconds" << std::endl;
//    
//    while (clock.getElapsedTime().asSeconds() < 6) {
//    }
//    std::cout << elapsed.asSeconds();
//    return 0;
//}


// spawn

//#include <SFML/System.hpp>
//#include <iostream>
//#include "RandomGenerator.hpp"
//#include "Enemy.hpp"
//
//
//int main() {
//    // 4s 33k 34k 35k cout 
//    // 16m 17m có rand
//    // 25m
//
//    int dokho = 0;
//    std::vector<Enemy> enemies;
//    
//    int chot1 = 10000;
//    int chot2 = 10000;
//    int heso1;
//    int heso2;
//    sf::Clock clock;
//    std::vector<Enemy> tmp; 
//    while (true) {
//        if (dokho == 0 || clock.getElapsedTime().asSeconds() > 4) {
//            /// backup spawn
//            for (int i = 0; i < tmp.size(); i++) {
//                tmp[i].element.inE();
//                tmp[i].spawn();
//            }
//            tmp.clear();
//            //
//            std::cout << "wave: " << dokho << std::endl;
//            clock.restart();
//            heso1 = dokho * 200;
//            heso2 = dokho * 100;
//            dokho++;
//            if (chot1 - heso1 < 0) chot1 = 0;
//            else chot1 -= heso1;
//            if (chot2 - heso2 < 0) chot2 = 0;
//            else chot2 -= heso2;
//            int x = randomQuantityEmemy(chot1, chot2);
//            std::cout << "soluong: " << x << std::endl;
//            for (int i = 0; i < x; i++) {
//                Enemy tmp0;
//                tmp0.complex = randomComplex(chot1, chot2);
//                tmp0.init();
//                std::cout << tmp0.complex << ": ";
//                tmp0.element.inE();
//                tmp.push_back(tmp0);//
//            }
//        }
//        sf::Time time = clock.getElapsedTime();
//        for (int i = 0; i < tmp.size(); i++) {
//            if (tmp[i].timeSpawn.asMilliseconds() < time.asMilliseconds() // 
//                && tmp[i].isSpawn == false)
//            {
//                // spawn
//                tmp[i].element.inE();
//                tmp[i].spawn();
//                //
//                tmp.erase(tmp.begin() + i);
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
