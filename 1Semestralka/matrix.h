#pragma once
#include "heap_monitor.h"
#include <iostream>

using namespace std;
namespace structures
{

	/// <summary> Matica. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
	template<typename T>
	class Matrix : public Structure
	{
	public:
		/// <summary> Operacia klonovania. Vytvori a vrati duplikat udajovej struktury. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override = 0;

		/// <summary>
		/// Operator priradenia.
		/// </summary>
		/// <param name="other">Matica, z ktorej ma prebrat vlastnosti.</param>
		/// <returns> Adresa, na ktorej sa tato matica nachadza po priradeni.</returns>
		Structure& operator=(const Structure& other) override = 0;

		/// <summary> Vrati velkost udajovej struktury. </summary>
		/// <returns> Velkost udajovej struktury. </returns>
		virtual size_t size() const = 0;

		/// <summary>
		/// Vrati data na zadanych indexoch.
		/// </summary>
		/// <param name="indRow">Riadkovy index.</param>
		/// <param name="indColumn">Stlpcovy index.</param>
		/// <returns>Data</returns>
		virtual T accessData(const int indRow, const int indColumn) const = 0;
		
		/// <summary>
		/// Nastavi na zadane indexy data.
		/// </summary>
		/// <param name="indRow">Riadkovy index.</param>
		/// <param name="indColumn">Stlpcovy index.</param>
		/// <param name="data">Data, ktore sa maju nastavit.</param>
		virtual void setData(const int indRow, const int indColumn, const T data) const = 0;

		/// <summary>
		/// Zmeni rozmery matice.
		/// </summary>
		/// <param name="a">Velkost riadku.</param>
		/// <param name="b">Velkost stlpca</param>
		virtual void setDimensions(int a, int b);

		/// <summary>
		/// Vrati pocet riadkov matice.
		/// </summary>
		/// <returns>Pocet riadkov matice.</returns>
		virtual int getRows() = 0;

		/// <summary>
		/// Vrati pocet stlpcov matice.
		/// </summary>
		/// <returns>Pocet stlpcov matice</returns>
		virtual int getColumns() = 0;

		/// <summary> Destruktor. </summary>
		virtual ~Matrix();
	protected:
		/// <summary> Konstruktor. </summary>
		Matrix();
	};


	template<typename T>
	inline void Matrix<T>::setDimensions(const int a, const int b)
	{
	}

	template<typename T>
	inline Matrix<T>::~Matrix()
	{
	}

	template<typename T>
	inline Matrix<T>::Matrix()
	{
	}

}