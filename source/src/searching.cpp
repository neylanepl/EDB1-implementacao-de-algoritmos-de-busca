/*!
 * \file searching.cpp
 * Binary search, Linear search, Upper bound, lower bound implementation for an array of integers.
 * \author Neylane Lopes
 * \date June 22th, 2021.
 */

#include "searching.h"

namespace sa {

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {
        while (first < last){
            if (value == *first){
                return first;
            }
            first+=1;
        }
        return last; // STUB
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
        value_type * meio;
        value_type *  auxiliar_last = last;

        while (first < last){
            meio = first + (last-first)/2;

            if (value == *meio){
                return meio ;
            }

            if (value > *meio){
                first = meio + 1;
            }
            else{
                last = meio;
            }

        }

        return auxiliar_last; // STUB
    }

    /*!
     * Executa uma pesquisa binária recursiva por 'value' em '[first; last)' e retorna um ponteiro para a localização de 'value' no range '[first; last)', ou 'nullptr' se nenhum elemento for encontrado.
     * 
     * \param first Ponteiro para o primeiro elemento do range.
     * \param last Ponteiro para a posição logo após o último elemento do range.
     * \param value O valor que procuramos.
     */
    value_type * bsearchRFake(value_type * first, value_type * last, value_type value)
    {
        if (last > first) {
            value_type * meio = first + (last - first) / 2;
      
            if (value == *meio){
                return meio;
            }
      
            if (value > *meio){
                return bsearchRFake(meio + 1, last, value);
            }
            else{
                return bsearchRFake(first, meio, value);
            }
        }

        return nullptr;
    }


    /*!
     * Realiza a chamada da função 'bsearchRFake' e retorna um ponteiro para a localização de 'value' no range '[first; last)', ou 'last' se nenhum elemento for encontrado.
     * 
     * \param first Ponteiro para o primeiro elemento do range.
     * \param last Ponteiro para a posição logo após o último elemento do range.
     * \param value O valor que procuramos.
     */
    value_type * bsearchR(value_type * first, value_type * last, value_type value)
    {   
        value_type * retorno = bsearchRFake( first, last, value );

        if (retorno != nullptr){
            return retorno;
        }
        
        return last; 
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {   
        value_type * meio;

        while (first < last){
            meio = first + (last-first)/2;

            if (value <= *meio){
                last = meio;
            }
            else{
                first = meio + 1;
            }

        }

        return last; // STUB
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
        value_type * meio;

        while (first < last){
            meio = first + (last-first)/2;

            if (value >= *meio){
                first = meio + 1;
            }
            else{
                last = meio;
            }
        }

        return last;
    }
}

