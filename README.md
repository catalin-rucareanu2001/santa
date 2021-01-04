# santa
Proiect Laborator POO

Având în vedere că suntem în 2020, Moș Crăciun s-a hotărât să își automatizeze procesul de livrare al cadourilor, astfel voi sunteți datori să îl ajutați. Pentru a realiza acest sistem, Moș Crăciun a stabilit o serie de specificații funcționale pe care voi trebuie să le implementați:

Moș Crăciun primește scrisori de la copii cu ce își doresc. Fiecare scrisoare conține următoarele atribute:
Nume
Prenume
Vârstă
Oraș
Wishlist (acesta este o listă de mai multe jucării pe care fiecare copil și le dorește)
Culoare plic: roz pentru fetițe și albastru pentru băieței

Minim 5 copii trimit scrisori.

Odată ce ajung scrisorile la Polul Nord, elfii se ocupă de ele.
Pentru fiecare copil se acordă un buget, în funcție dacă a fost cuminte sau nu. Pentru fiecare copil cuminte se acordă o sumă de 100$, iar pentru unul rău se acordă 10$. Elfii au deja o listă cu statusul fiecărui copil și atribuie suma în funcție de acesta.
Elfii parcurg după lista și se uită ce au copiii pe wishlist. După care se uită pe inventar și văd dacă acele jucării există la ei în atelier. 
Dacă există le pun în punga de cadouri în ordinea înșiruită.
Dacă au mai multe lucruri pe listă decât permite bugetul, se adaugă în pungă în ordinea lor până să se depășească și apoi se adaugă o acadea pentru fiecare dolar necheltuit.
Dacă nu există nimic pe inventar se va da un cadou default.
Dacă ce e pe listă depășește din start bugetul se va da un cadou default care valorează fix 100$ sau 10$ în funcție de copil. (este același cadou default)
Elfii dau mai departe lista cu cadouri trolilor. 
Elfii dau mai departe numărul de acadele Doamnei Crăciun.
Elfii dau mai departe lista cu orașe lui Moș Crăciun.

Să se afișeze fiecare copil ce cadou va primi.

Trolii primesc de la elfi lista cu cadouri și împachetează fiecare cadou cu un ambalaj specific pentru fete și unul specific pentru băieți.
	De asemenea, trolii pun și un cărbune în punga fiecărui copil rău.

Să se afișeze câte ambalaje pentru fete și câte ambalaje pentru băieți au folosit trolii.

Doamna Crăciun primește lista cu numărul de acadele pe care trebuie să le facă, de la elfi, iar de la troli numărul de cărbuni folosiți. 
Fiecare cărbune valorează 0.5$.
La final doamna Crăciun calculează bugetul extra (acadele plus cărbuni). 

Să se afișeze suma totală.

Moș Crăciun primește lista cu orașe de la elfi și calculează drumul critic în număr de kilometrii și ordinea destinațiilor având în vedere că el pleacă cu sania din aeroportul Rovaniemi din Laponia (Finlanda). (nu se ia în calcul și drumul de întoarcere)
	Useful: https://www.distancecalculator.net/
Minim 4 orașe la fiecare țară.

Înainte să plece, Doamna Crăciun vrea și ea să afle traseul lui Moș Crăciun, așa că îl împărtășește și cu ea.

	Să se afișeze traseul cu numărul de kilometrii parcurși și ordinea de parcurgere a orașelor.

În rezolvarea temei trebuie să fie acoperite următoarele concepte POO:
Clase și obiecte
Constructori și destructori
Încapsulare
Moștenire
Polimorfism
Abstractizare
Templates
Exceptions

Tema valorează jumătate din punctajul de pe laborator și se va nota de la 0 la 10 astfel:
6p implementare completă
1p lizibilitate, stil, structură, comentarii
3p susținerea temei și validarea conceptelor de poo în ultimul laborator de POO

Tema trebuie încărcată pe Github, într-un repository private la care să îmi dați acces (danielcdi , chisdanielioan@gmail.com) până la data de 17 Ianuarie.

La ultimul laborator se vor prezenta temele acompaniate de câteva întrebări din partea mea și se va calcula punctajul final.

Spor la treabă!
