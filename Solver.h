#pragma once


#include <vector>
using namespace std;


// Точка на плоскости.
struct Point
{
	double x;                            // Координата x.
	double y;                            // Координата y.
};

// Квадрат на плоскости.
struct Square
{
	bool covered = false;                // Флаг покрытия квадрата точкой.
	Point corner{};                      // Координаты левого нижнего угла.
};

// Отрезок на прямой.
struct Segment
{
	double begin;                         // Координата начала.
	double end;                           // Координата конца.
};

// Набор данных для задачи.
struct TaskData
{
	unsigned int side_length;           // Длина стороны одного квадрата.
	vector<Square> squares;             // Вектор квадратов.
};


// Класс, решающий задачу.
class Solver
{
	private:

	TaskData data;                      // Набор данных для задачи.

	/*
	 * Если точка принадлежит квадрату, возвращает true, иначе - false.
	 *
	 * Параметры:
	 * Point point - точка
	 * Square square - квадрат
	 * unsigned int side_length - сторона квадрата
	 */
	static bool belong(Point point, Square square, unsigned int side_length);

	/*
	 * Если квадраты пересекаются, возвращает указатель на
	 * координаты середины их пересечения, иначе - nullptr.
	 *
	 * Параметры:
	 * unsigned int first - номер первого квадрата
	 * unsigned int second - номер второго квадрата
	 */
	Point* middle(unsigned int first, unsigned int second);


	public:

	/*
	 * Конструктор.
	 */
	explicit Solver(TaskData data) : data(move(data)) {}

	/*
	 * Решает задачу покрытия квадратов точками.
	 *
	 * После выполнения функции в векторе points хранятся координаты точек покрытия.
	 * В зависимости от переданного параметра улучшает точность или скорость работы.
	 *
	 * Возвращает количество шагов, за которое была решена задача.
	 * Под шагом понимается анализ пары квадратов на предмет их пересечения, и
	 * вычисление координат середины этого пересечения в соответствующем случае.
	 *
	 * Параметры:
	 * vector<Point> &points - координаты точек покрытия
	 * bool time_accuracy - true улучшает точность, false - скорость работы
	 */
	unsigned int cover(vector<Point> &points, bool accuracy_time = true);
};