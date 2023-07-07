#pragma once
#include "heap_monitor.h"
#include "vector/vector.h"
#include "matrix.h"

namespace structures
{

	/// <summary> Matica implementovana vektorom v suvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class Contiguous_Matrix : public Matrix<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		Contiguous_Matrix();

		/// <summary>
		/// Konstruktor parametricky.
		/// </summary>
		/// <param name="indRow">Velkost riadkov.</param>
		/// <param name="indColumn">Velkost stlpcov</param>
		/// <param name="data">Inicializacne data.</param>
		Contiguous_Matrix(int indRow, int indColumn, T data);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Matica, z ktorej sa prevezmu vlastnosti. </param>
		Contiguous_Matrix(const Contiguous_Matrix<T>& other);

		/// <summary> Destruktor. </summary>
		~Contiguous_Matrix();

		/// <summary>
		/// Operator priradenia.
		/// </summary>
		/// <param name="other">Matica, z ktorej ma prebrat vlastnosti.</param>
		/// <returns> Adresa, na ktorej sa tato matica nachadza po priradeni.</returns>
		Contiguous_Matrix<T>& operator=(const Contiguous_Matrix<T>& other);

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat matice. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary>
		/// Operator priradenia.
		/// </summary>
		/// <param name="other">Matica, z ktorej ma prebrat vlastnosti.</param>
		/// <returns> Adresa, na ktorej sa tato matica nachadza po priradeni.</returns>
		Structure& operator=(const Structure& other) override;

		/// <summary> Vrati pocet prvkov v matici. </summary>
		/// <returns> Pocet prvkov v matici. </returns>
		size_t size() const override;

		/// <summary>
		/// Vrati data na zadanych indexoch.
		/// </summary>
		/// <param name="indRow">Riadkovy index.</param>
		/// <param name="indColumn">Stlpcovy index.</param>
		/// <returns>Data</returns>
		T accessData(const int indRow, const int indColumn) const override;

		/// <summary>
		/// Nastavi na zadane indexy data.
		/// </summary>
		/// <param name="indRow">Riadkovy index.</param>
		/// <param name="indColumn">Stlpcovy index.</param>
		/// <param name="data">Data, ktore sa maju nastavit.</param>
		void setData(const int indRow, const int indColumn, const T data) const override;

		/// <summary>
		/// Zmeni rozmery matice.
		/// </summary>
		/// <param name="a">Velkost riadku.</param>
		/// <param name="b">Velkost stlpca</param>
		void setDimensions(int a, int b);

		/// <summary>
		/// Vrati pocet riadkov matice.
		/// </summary>
		/// <returns>Pocet riadkov matice.</returns>
		int getRows();

		/// <summary>
		/// Vrati pocet stlpcov matice.
		/// </summary>
		/// <returns>Pocet stlpcov matice</returns>
		int getColumns();
	private:
		/// <summary> Vector s datami. </summary>
		Vector* vector_;
		/// <summary> Pocet prvkov v matici. </summary>
		size_t size_;

		/// <summary> Pocet riadkov v matici. </summary>
		int rows;
		/// <summary> Pocet stlpcov v matici </summary>
		int columns;
	};

	template<typename T>
	inline Contiguous_Matrix<T>::Contiguous_Matrix()
	{
	}

	template<typename T>
	inline Contiguous_Matrix<T>::Contiguous_Matrix(int pRows, int pColumns, T data) :
		Matrix<T>::Matrix(),
		vector_(new Vector(static_cast<size_t>(pRows * pColumns * sizeof(T)))),
		size_(pRows * pColumns),
		columns(pColumns),
		rows(pRows)
	{
		for (int i = 0; i < static_cast<int>(size_); i++)
		{
			*(reinterpret_cast<T*>(vector_->getBytePointer(i * sizeof(T)))) = data;
		}
	}


	template<typename T>
	inline Contiguous_Matrix<T>::Contiguous_Matrix(const Contiguous_Matrix<T>& other) :
		vector_(new Vector(other.rows* other.columns * sizeof(T))),
		size_(other.rows* other.columns),
		columns(other.columns),
		rows(other.rows)
	{
	}

	template<typename T>
	inline Contiguous_Matrix<T>::~Contiguous_Matrix()
	{
		delete vector_;
		vector_ = nullptr;
		size_ = 0;
		rows = 0;
		columns = 0;
	}

	template<typename T>
	inline Contiguous_Matrix<T>& Contiguous_Matrix<T>::operator=(const Contiguous_Matrix<T>& other)
	{
		if (this != &other)
		{
			if (rows == other.rows && columns == other.columns) {
				*vector_ = *other.vector_;
				size_ = other.size_;
				rows = other.rows;
				columns = other.columns;
			}			
		}
		return *this;
	}

	template<typename T>
	inline Structure* Contiguous_Matrix<T>::clone() const
	{
		return new Contiguous_Matrix<T>(*this);
	}

	template<typename T>
	inline Structure& Contiguous_Matrix<T>::operator=(const Structure& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Contiguous_Matrix<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline size_t Contiguous_Matrix<T>::size() const
	{
		return size_;
	}
	template<typename T>
	inline T Contiguous_Matrix<T>::accessData(const int indRow, const int indColumn) const
	{
		return *(reinterpret_cast<T*>(vector_->getBytePointer((indRow * columns * sizeof(T)) + (indColumn * sizeof(T)))));
	}

	template<typename T>
	inline void Contiguous_Matrix<T>::setData(const int indRow, const int indColumn, const T data) const
	{
		*(reinterpret_cast<T*>(vector_->getBytePointer((indRow * columns * sizeof(T)) + (indColumn * sizeof(T))))) = data;
	}

	template<typename T>
	inline void Contiguous_Matrix<T>::setDimensions(int a, int b)
	{
		Vector* newVector = new Vector(a*b*sizeof(T));
		if (a * b > size_)
		{
			//zvacsujem
			vector_->copy(*vector_, 0, *newVector, 0, vector_->size());
			//zmensujem
			//vector_->copy(*vector_, 0, *newVector, 0, newVector->size());
		}
		size_t oldSize = size_;
		rows = a;
		columns = b;
		size_ = a * b;
		int random = rand() % 100;
		for (int i = static_cast<int>(oldSize); i < static_cast<int>(size_); i++)
		{
			*(reinterpret_cast<T*>(newVector->getBytePointer(i * sizeof(T)))) = random;
		}
		*vector_ = *newVector;
		delete newVector;
	}

	template<typename T>
	inline int Contiguous_Matrix<T>::getRows()
	{
		return rows;
	}

	template<typename T>
	inline int Contiguous_Matrix<T>::getColumns()
	{
		return columns;
	}
}


