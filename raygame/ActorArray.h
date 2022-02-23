#pragma once
#include <exception>

class Actor;

template<typename T>
class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();
	/// <summary>
	/// Adds an actor to the end of the array
	/// </summary>
	/// <param name="actor">The new actor to add to the array</param>
	void add(T actor);

	/// <summary>
	/// Removes the actor from the array
	/// </summary>
	/// <param name="actor">The actor to remove</param>
	/// <returns>False if the actor is not in the array</returns>
	bool remove(T actor);
	/// <summary>
	/// Removes an actor from the array
	/// </summary>
	/// <param name="index">The index to remove from the array</param>
	/// <returns>False if the index is out of bounds</returns>
	bool remove(int index);

	/// <summary>
	/// Gets an actor from the array
	/// </summary>
	/// <param name="index">The index of the desired actor</param>
	/// <returns>The actor found at the index or nullptr if the index was out of bounds</returns>
	T get(int index);

	/// <summary>
	/// Gets the length of the array
	/// </summary>
	int getLength() { return m_count; }

	/// <summary>
	/// Checks if the actor is in the array
	/// </summary>
	/// <param name="actor">A reference to the actor to use to check</param>
	/// <returns>False if the actor is not in the array</returns>
	bool contains(T actor);

    T operator [](int index);

private:
	T* m_items;
	int m_count;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
    m_count = 0;
    m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
}

template<typename T>
inline void DynamicArray<T>::add(T actor)
{
    //Create a new array with a size one greater than our old array
    T* appendedArray = new T * [m_count + 1];
    //Copy the values from the old array to the new array
    for (int i = 0; i < m_count; i++)
    {
        appendedArray[i] = m_items[i];
    }

    //Set the last value in the new array to be the actor we want to add
    appendedArray[m_count] = actor;
    //Set old array to hold the values of the new array
    m_items = appendedArray;
    m_count++;
}

template<typename T>
inline bool DynamicArray<T>::remove(T actor)
{
    //Check to see if the actor was null
    if (!actor)
    {
        return false;
    }

    bool actorRemoved = false;
    //Create a new array with a size one less than our old array
    T* newArray = new T * [m_count - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_count; i++)
    {
        if (actor != m_items[i])
        {
            newArray[j] = m_items[i];
            j++;
        }
        else
        {
            actorRemoved = true;
        }
    }
    //Set the old array to the new array
    if (actorRemoved)
    {
        m_items = newArray;
        m_count--;
    }
    //Return whether or not the removal was successful
    return actorRemoved;
}

template<typename T>
inline bool DynamicArray<T>::remove(int index)
{
    //Check to see if the index is outside the bounds of our array
    if (index < 0 || index >= m_count)
    {
        return false;
    }

    bool actorRemoved = false;

    //Create a new array with a size one less than our old array 
    T* newArray = new T * [m_count - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_count; i++)
    {
        //If the current index is not the index that needs to be removed,
        //add the value into the old array and increment j
        if (i != index)
        {
            newArray[j] = m_items[i];
            j++;
        }
        else
        {
            delete m_items[i];
            actorRemoved = true;
        }
    }

    //Set the old array to be the tempArray
    m_items = newArray;
    m_count--;
    return actorRemoved;
}

template<typename T>
inline T DynamicArray<T>::get(int index)
{
    //Return false if the index is out of bounds
    if (index < 0 || index >= m_count)
        return nullptr;

    return m_items[index];
}

template<typename T>
inline bool DynamicArray<T>::contains(T actor)
{
    //Iterate through actor array
    for (int i = 0; i < m_count; i++)
    {
        //return the current actor if it matches the argument
        if (m_items[i] == actor)
            return true;
    }

    return false;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
    if (index > 0 || index < getLength())
    {
        return m_items[index];
    }

    throw std::exception("Index was outside the bounds of the array");
}


