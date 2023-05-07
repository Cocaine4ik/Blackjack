#pragma once

/**
 * @brief Template singleton base class
 * @tparam T template
*/
template <typename T>
class Singleton
{
public:
	/**
	 * @brief Get instance
	 * @return &T reference to the Singleton instance
	*/
	static T& GetInstance() { static T instance; return instance; }

protected:
	/**
	 * @brief Default constructor
	*/
	Singleton() = default;

	/**
	 * @brief Delete copy constructor
	*/
	Singleton(const Singleton&) = delete;

	/**
	 * @brief Delete assigment operator
	*/
	Singleton& operator = (const Singleton&) = delete;

	/**
	 * @brief Default destructor
	*/
	virtual ~Singleton() = default;

};