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
	double begin;                        // Координата начала.
	double end;                          // Координата конца.
};

// Набор данных для задачи.
struct TaskData
{
	unsigned int side_length;           // Длина стороны одного квадрата.
	vector<Square> squares;             // Квадраты.
};

// Результаты решения задачи.
struct TaskResults
{
	vector<Square> squares;             // Квадраты.
	vector<Point> points;               // Точки покрытия.

	unsigned int steps;                 // Количество шагов в тесте.
	double time;                        // Время, затраченное на тест.
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
	 */
	bool belong(Point point, Square square);

	/*
	 * Если квадраты пересекаются, возвращает указатель на
	 * координаты середины их пересечения, иначе - nullptr.
	 *
	 * Параметры:
	 * unsigned int first - номер первого квадрата
	 * unsigned int second - номер второго квадрата
	 */
	Point* middle(unsigned int first, unsigned int second);

	/*
	 * Определяет, пересекаются ли отрезки.
	 *
	 * Если первый пересекается со вторым слева, возвращает -1.
	 * Если первый пересекается со вторым справа, возвращает 1.
	 * Если первый полностью лежит во втором, возвращает 2.
	 * Во всех остальных случаях возвращает 0.
	 */
	static int intersection(const Segment &first, const Segment &second);


	public:

	/*
	 * Конструктор.
	 */
	explicit Solver(TaskData data) : data(move(data)) {}

	/*
	 * Решает задачу покрытия квадратов точками.
	 *
	 * После выполнения функции points содержит координаты точек покрытия.
	 *
	 * Возвращает количество шагов, за которое была решена задача.
	 * Под шагом понимается анализ пары квадратов на предмет их пересечения.
	 *
	 * Параметры:
	 * vector<Point> &points - координаты точек покрытия
	 */
	unsigned int cover(vector<Point> &points);

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
	 * set<Point> &points - координаты точек покрытия
	 * bool time_accuracy - true улучшает точность, false - скорость работы
	 */
	//unsigned int old_cover(set<Point> &points, bool accuracy_time = true);
};