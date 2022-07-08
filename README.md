# weatherWidget

Widget Météo (Linux) en temps réel basé sur une API (https://weatherstack.com/).
La météo par défaut est celle de Paris, l'utilisateur peut par la suite rechercher la ville qu'il souhaite
Le widget intègre également un conseiller vestimentaire en fonction de la météo
mais également un conseiller en jardinerie qui conseille quels fruits et légumes planter ou ceuillir en fonction de la saison.


## Screenshot

![App Screenshot](https://i.imgur.com/xP1HCrk.png)


## Installation


#### Cloner le projet

```bash
git clone https://github.com/hmzaakun/weatherWidget
```

#### Aller dans le fichier puis

Installer/mettre à jour les libs

```bash
cd installer/ && ./installer.sh
```

#### Pour le lancer simplement

```bash
./launch.sh
```


## libs

 - [CURL](https://curl.se/libcurl/c/)
 - [json-C](https://json-c.github.io/json-c/)
 - [GTK](https://www.gtk.org/)
 - [glade](https://glade.gnome.org/)
