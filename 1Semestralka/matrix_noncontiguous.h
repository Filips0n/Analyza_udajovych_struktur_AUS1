#pragma once
#include "heap_monitor.h"
#include "matrix.h"
#include "array/array.h"

namespace structures
{

	/// <summary> Matica implementovana polom poli v nesuvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class Noncontiguous_Matrix : public Matrix<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		Noncontiguous_Matrix();

		/// <summary> Konstruktor parametricky. </summary>
		Noncontiguous_Matrix(const int indRow, const int indColumn, const T data);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Matica, z ktorej sa prevezmu vlastnosti. </param>
		Noncontiguous_Matrix(const Noncontiguous_Matrix<T>& other);

		/// <summary> Destruktor. </summary>
		~Noncontiguous_Matrix();

		/// <summary>
		/// Operator priradenia.
		/// </summary>
		/// <param name="other">Matica, z ktorej ma prebrat vlastnosti.</param>
		/// <returns> Adresa, na ktorej sa tato matica nachadza po priradeni.</returns>
		Noncontiguous_Matrix<T>& operator=(const Noncontiguous_Matrix<T>& other);

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
		/// <summary> Matica s datami. </summary>
		Array<Array<T>*> *matrix_;
		/// <summary> Pocet prvkov v matici. </summary>
		size_t size_;
		/// <summary> Pocet riadkov v matici. </summary>
		int rows;
		/// <summary> Pocet stlpcov v matici </summary>
		int columns;
	};

	template<typename T>
	inline Noncontiguous_Matrix<T>::Noncontiguous_Matrix()
	{
	}

	template<typename T>
	inline Noncontiguous_Matrix<T>::Noncontiguous_Matrix(const int pRow, const int pColumn, const T data) :
		Matrix<T>::Matrix(),
		size_(pRow* pColumn),
		columns(pColumn),
		rows(pRow)
	{
		matrix_ = new Array<Array<T>*>(rows);
		for (int i = 0; i < rows; i++) {
			(*matrix_)[i] = new Array<T>(columns);
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++) {
				(*(*matrix_)[i])[j] = data;
			}
		}
	}

	template<typename T>
	inline Noncontiguous_Matrix<T>::Noncontiguous_Matrix(const Noncontiguous_Matrix<T>& other) :
		size_(other.rows* other.columns),
		columns(other.columns),
		rows(other.rows)
	{
	}

	template<typename T>
	inline Noncontiguous_Matrix<T>::~Noncontiguous_Matrix()
	{
		for (size_t i = 0; i < matrix_->size(); i++)
		{
			delete (*matrix_)[i];
		}
		delete matrix_;
		matrix_ = nullptr;
		size_ = 0;
		rows = 0;
		columns = 0;
	}

	template<typename T>
	inline Noncontiguous_Matrix<T>& Noncontiguous_Matrix<T>::operator=(const Noncontiguous_Matrix<T>& other)
	{
		if (this != &other)
		{
			if (rows == other.rows && columns == other.columns) {
				*matrix_ = *other.matrix_;
				size_ = other.size_;
				rows = other.rows;
				columns = other.columns;
			}
		}
		return *this;
	}

	template<typename T>
	inline Structure* Noncontiguous_Matrix<T>::clone() const
	{
		return new Noncontiguous_Matrix<T>(*this);
	}

	template<typename T>
	inline Structure& Noncontiguous_Matrix<T>::operator=(const Structure& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Noncontiguous_Matrix<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline size_t Noncontiguous_Matrix<T>::size() const
	{
		return size_;
	}
	template<typename T>
	inline T Noncontiguous_Matrix<T>::accessData(const int indRow, const int indColumn) const
	{
		return (*(*matrix_)[indRow])[indColumn];
	}
	template<typename T>
	inline void Noncontiguous_Matrix<T>::setData(const int indRow, const int indColumn, const T data) const
	{
		(*(*matrix_)[indRow])[indColumn] = data;
	}

	template<typename T>
	inline void Noncontiguous_Matrix<T>::setDimensions(int a, int b)
	{
		rows = a;
		columns = b;
		size_ = a * b;
	}

	template<typename T>
	inline int Noncontiguous_Matrix<T>::getRows()
	{
		return rows;
	}

	template<typename T>
	inline int Noncontiguous_Matrix<T>::getColumns()
	{
		return columns;
	}
}


