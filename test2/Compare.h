/*! ****************************************************************************
 * @copyright   Miguel Grimm <miguelgrimm@gmail>
 *
 * @brief       Classe concreta de aritmética do comparador de magnitude.
 *
 * @file        Compare.h
 * @version     1.0
 * @date        27 Julho 2021
 *
 * @section     HARDWARES & SOFTWARES.
 *              +compiler     GDB online - C++ 17
 *              +revisions    Versão (data): Descrição breve.
 *                            ++ 1.0 (27 Julho 2021): Versão inicial.
 *
 * @section     AUTHORS & DEVELOPERS.
 *              +institution  UFAM - Universidade Federal do Amazonas.
 *              +courses      Engenharia da Computação / Engenharia Elétrica.
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *
 *                            Compilação e Depuração:
 *                            +teacher	  Miguel Grimm <miguelgrimm@gmail.com>
 *
 * @section     LICENSE
 *
 *              GNU General Public License (GNU GPL).
 *
 *              Este programa é um software livre; Você pode redistribuí-lo
 *              e/ou modificá-lo de acordo com os termos do "GNU General Public
 *              License" como publicado pela Free Software Foundation; Seja a
 *              versão 3 da licença, ou qualquer outra versão posterior.
 *
 *              Este programa é distribuído na esperança de que seja útil,
 *              mas SEM QUALQUER GARANTIA; Sem a garantia implícita de
 *              COMERCIALIZAÇÃO OU USO PARA UM DETERMINADO PROPÓSITO.
 *              Veja o site da "GNU General Public License" para mais detalhes.
 *
 * @htmlonly    http://www.gnu.org/copyleft/gpl.html
 *
 * @section     REFERENCES.
 *              + NASCIMENTO, Miguel G. do. Anotações de aula da disciplina de
 *                Arquitetura de Sistemas Digitais. Ufam, 2021.
 *              + NASCIMENTO, Miguel G. do. AnotaC'C5es de aula da disciplina de
 *                Eletrônica Digital II. Ufam, 2021.
 * *****************************************************************************
 */


#ifndef C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_COMPARE_H_
#define C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_COMPARE_H_


#include "Flow.h"


/*! ----------------------------------------------------------------------------
 *  @brief    A classe implementa o comparador de magnitude.
 *
 *  @use      Sequência de uso dos serviços da classe.
 *
 *            ++ Compare   cmp (dataBitSize);
 *
 *            ++ cmp.setEnable (enable);
 *            ++ cmp.setDataA (dataA);
 *            ++ cmp.setDataB (dataB);
 *            ++ active = cmp.getActive ();
 *
 *            ++ cmp.doCompare ();
 *
 *            ++ gleOut = cmp.getGreastLessEqualOut ();
 *
 *            ++ gt = cmp.getGreastThen ();
 *            ++ ge = cmp.getGreastOrEqual ();
 *            ++ lt = cmp.getLessThen ();
 *            ++ le = cmp.getLessOrEqual ();
 *            ++ eq = cmp.getEqual ();
 *            ++ ne = cmp.getNotEqual ();
 * -----------------------------------------------------------------------------
 */
class Compare : public Flow
{


public:


  Compare (int dataBitSize = 4) : Flow (dataBitSize)
  {
    /*! Zera as saidas */
    gleOut = 0;
  }


  /*! --------------------------------------------------------------------------
   *  @brief       Realiza a operação de comparação dos dados e casteamento.
   *  --------------------------------------------------------------------------
   */
  void doArithmetic () {

    if ((enable == 1)  && (active == 1))
    {
	  /*! Entrada de cascateamento Igual é a menos prioritária */
	  compareDatas ();
    }
    else
    {
      /*! Comparador desabilitado ou dado de entrada inválido */
      gleOut = 0b000;
      active = 0;
    }

  }


  /*! --------------------------------------------------------------------------
   *  @brief       Realiza a operação de comparação com os dados de entrada.
   *  --------------------------------------------------------------------------
   */
  void compareDatas ()
  {
    if (dataA > dataB)
    {
      /*! dataA é maior que dataB */
      gleOut = 0b100;
    }
    else
    {
      if (dataA < dataB)
	  {
	    /*! dataA é menor que dataB */
	    gleOut = 0b010;
	  }
      else
	  {
	    /*! dataA é igual a dataB */
	    gleOut = 0b001;
	  }  //<! if (dataa < datab).
    }  //<! if (dataa > datab)
  }


  /*! --------------------------------------------------------------------------
   *  @brief      Verificação se o resultado da operação é maior.
   *  
   *  @return     1, se o resultado da comparação é maior e
   *              0, em caso contrário.
   *  --------------------------------------------------------------------------
   */
  int getGreastThenOut ()
  {
    int   greast;

    greast = (gleOut >> 2) & 0b001;

    return greast;

  }


  /*! --------------------------------------------------------------------------
   *  @brief      Verificação se o resultado da operação é maior ou igual.
   *  
   *  @return     1, se o resultado da comparação é maior ou igual e
   *              0, em caso contrário.
   *  --------------------------------------------------------------------------
   */
  int getGreastOrEqualOut ()
  {
    int   greast, equal;

    greast = (gleOut >> 2) & 0b001;
    equal  = gleOut & 0b001;

    return  greast & equal;

  }


  /*! --------------------------------------------------------------------------
   *  @brief      Verificação se o resultado da operação é menor.
   *  
   *  @return     1, se o resultado da comparação é menor e
   *              0, em caso contrário.
   *  --------------------------------------------------------------------------
   */
  int getLessThenOut ()
  {
    int   less;

    less = (gleOut >> 1) & 0b001;

    return less;

  }


  /*! --------------------------------------------------------------------------
   *  @brief      Verificação se o resultado da operaçãoo é  menor ou igual.
   *  
   *  @return     1, se o resultado da comparação é menor ou igual e
   *              0, em caso contrário.
   *  --------------------------------------------------------------------------
   */
  int getLessOrEqualOut ()
  {

    int   less, equal;

    less = (gleOut >> 1) & 0b001;
    equal  = gleOut & 0b001;

    return  less & equal;

  }


  /*! --------------------------------------------------------------------------
   *  @brief      Verificação se o resultado da operação é igual.
   *
   *  @return     1, se o resultado da comparação é igual e
   *              0, em caso contrário.
   *  --------------------------------------------------------------------------
   */
  int getEqualOut ()
  {
    int   equal;

    equal = (gleOut & 0b001);

    return equal;

  }


  /*! --------------------------------------------------------------------------
   *  @brief      Verificação se o resultado da operação é diferente.
   *
   *  @return     1, se o resultado da comparação é diferente e
   *              0, em caso contrário.
   *  --------------------------------------------------------------------------
   */
  int getNotEqualOut ()
  {
    int   notEqual;

    if ((enable == 1) && (active == 1))
    {
      notEqual = gleOut & 0b001;
      notEqual = (notEqual == 0) ? 1 : 0;
    }
    else
    {
      notEqual = 0;
    }

    return notEqual;

  }


private:


  void doFlow ()
  {
    /*! Corpo vazio */
  }


  /*! --------------------------------------------------------------------------
   *  @brief      Verifica se dado fornecido é válido.
   *  --------------------------------------------------------------------------
   */
  bool isTheDataValid (int data)
  {
    bool   flag = false;

    if (isRange (data, 0, maximumData))
    {
      /*! O dado em Ascii é um número hexa */
      flag = true;
    
    }
    else 
    {
      /*! O dado em Ascii NÃO é um número hexa */
      flag = false;
    }

    return flag;
  }


  /*! Saídas da aritmética */
  int   gleOut;

};


#endif // C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_COMPARE_H_
