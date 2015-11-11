# ContainingController

2. Opdracht
Er moeten 3 van elkaar onafhankelijke programma's geschreven worden.
Ten eerste een controller die ervoor zorgt dat de AGV's op de juiste manier aangestuurd worden
zodat 1) de auto's, schepen en treinen zo snel mogelijk gelost respectievelijk geladen worden en 2)
door de AGV's in totaal een zo kleine mogelijke afstand afgelegd wordt.

1) is nodig voor de minimalisatie van de kosten van de aan- en afleveranciers, want die moeten
bijvoorbeeld havengelden betalen voor de tijd die de schepen afgemeerd liggen. 

2) is nodig voor de minimalisatie van de interne bedrijfskosten, zodat de prijs voor de overslag (en opslag) zo laag
mogelijk is. De controller krijgt z'n gegevens vanuit een file met container-data (dwz de treinen,
vrachtauto's of schepen met inkomende containers), de containers zelf, en de uitgaande containers
(dwz de treinen, vrachtauto's of schepen met containers).
Ten tweede een simulator die ervoor zorgt dat het gehele terrein in 3D op het scherm te zien is,
inclusief containers, bewegende AGV's en kranen. De simulator krijgt z'n aansturing van de
controller.
Ten derde een Management Interface op een mobile (Android of iOS) platform.
Dit is een view waarin management informatie getoond moet worden. Dat wil zeggen er moet op
aanvraag van de gebruiker een snapshot van de data getoond worden.
De gewenste management informatie is een grafiek (bijvoorbeeld een staafdiagram) waarin
actuele aantallen containers per categorie getoond worden. Categorieën zijn de verschillende
platforms (trein, vrachtauto, zeeschip, binnenschip en opslag), containers op AGV's en diversen
(als een container niet in een van de andere categorieën valt).
Het koppelen van het Android platform gaat draadloos.
Er zijn android tablets beschikbaar maar de opdrachtgever heeft er geen bezwaar tegen als er een
smartphone of eigen tablet gebruikt wordt. Alle mobiele apparaten zijn welkom.
