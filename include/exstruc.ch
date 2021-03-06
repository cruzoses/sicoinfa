/*
旼 Program 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
�   Aplication: Header file for class TExStruc                             �
�         File: STRUC.CH                                                   �
�       Author: Ignacio Ortiz de Z＄iga Echeverr죂                         �
�          CIS: Ignacio Ortiz (100042,3051)                                �
�         Date: 01/03/97                                                   �
�         Time: 12:20:07                                                   �
�    Copyright: 1997 by Ortiz de Zu쨒ga, S.L.                              �
읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
*/

#xcommand STRUC <oSt> ;
       => ;
          <oSt> := StrucBegin(<(oSt)>)

#xcommand END STRUC ;
       => ;
          StrucEnd()

#xcommand ENDSTRUC ;
       => ;
          END STRUC

#xcommand MEMBER <xData, ...> ;
                 [ AS <cType:LOGICAL,NUMERIC,NUMBER,CHARACTER,DATE,BLOCK,ARRAY,OBJECT> ] ;
                 [ <def: DEFAULT, INIT> <default> ] ;
                 [ SIZE <nSize> ] ;
        => ;
          StrucMember( {<(xData)>}, [<(cType)>], <default>, <nSize> )

#xcommand MEMBER <oSt> AS STRUC ;
       => ;
          StrucBegin(<(oSt)>)
