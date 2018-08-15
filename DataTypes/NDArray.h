#pragma once

template <class Datatype>
class NDArray
{
public:
	NDArray( int p_size )
	{
		m_array = new Datatype[p_size];
		m_size = p_size;
	}

	~NDArray()
	{
		if( m_array != nullptr )
		{
			delete[] m_array;
		}
		m_array = 0;
	}

	void Resize(int p_size)
	{
		Datatype* newarray = new Datatype[p_size];
		if(newarray == nullptr)
		{
			return;
		}

		int min;
		if(p_size < m_size)
		{
			min = p_size;
		}
		else
		{
			min = m_size;
		}

		for( int Index = 0; Index < min; Index++ )
		{
			newarray[Index] = m_array[Index];
		}

		m_size = p_size;

		if(m_array != 0)
		{
			delete[] m_array;
		}

		m_array = newarray;
	}

	Datatype& operator[] ( int p_index )
	{
		return m_array[p_index];
	}

	void Insert( Datatype p_item, int p_index)
	{
		int index;
		for( index = m_size -1; index > p_index; index--)
		{
			m_array[index] = m_array[index-1];
		}
		m_array[p_index] = p_item;
	}

	void Remove(int p_index)
	{ 
		for( int index = p_index + 1; index < m_size; index++)
		{
			m_array[index -1] = m_array[index];
		}
	}

	int Size()
	{
		return m_size;
	}

private:
	Datatype* m_array;
	int m_size;
};