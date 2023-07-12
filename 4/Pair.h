#include <string>
class Pair {
protected:
	double x;
	double y;
public:
	/*Контруктор по умолчанию */
	Pair();
	/*Конструктор с параметрами
	@param _x - 1 число
	@param _y - 2 число*/
	Pair(double _x, double _y);
	/*Метод  изменяющий поле x
	@param _x - новое значение поля x*/
	void setX(double _x);
	/*Метод  изменяющий поле у
	@param _у - новое значение поля у*/
	void setY(double _y);
	/*Метод возвращающий поле x
	@return значение поля x*/
	double getX();
	/*Метод возвращающий поле y
	@return значение поля y*/
	double getY();
	/*Метод произведения чисел
	@return произведение x и y*/
	double compozition();
	/*Метод toString
	@return строка значений полей*/
	std::string toString();
};