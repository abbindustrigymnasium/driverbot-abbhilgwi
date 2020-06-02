# Driverbot - abbhilgwi

## Vad ingår
Dessa komponenter ingår i denna robotstyrbas

 ### App.vue
  I App.vue binds alla komponenter ihop men även en dialogruta finns att klicka upp för att ställa in vilken MQTT broker man ska ansluta   till.

 ### Buttonsv2.vue
  I Buttonsv2.vue finns en mer avancerad styrmöjlighet för att skicka kommandon för fram, bak, vänster och höger, snett upp och snett     ner till mqtt. MQTT topicen är döpt till drive. Det finns fyra knappar för att reglera hastighet.

### Logger.vue
  En Komponent som loggar vilka kommandon som skickas över MQTT, vill du själv förbättra den så kan du göra att den läser av kommandon     som även mikrokontrolllen skickar.

### store.js
  Här sparas alla viktiga variabler som skickas mellan komponenterna.

### Project setup
   npm install
### Compiles and hot-reloads for development
   npm run serve
### Compiles and minifies for production
   npm run build
### Run your tests
   npm run test
### Lints and fixes files
   npm run lint
### Customize configuration
   See Configuration Reference.


## Preliminär plannering - skriven 2020-03-27

* Fokus på microkontrollern
  * Förstå kod
  * Anpassa kod
* Fixa mqtt
  * Koppla till arduino
* Hemsidan
  * Förstå kod
  * Anpassa kod
* Skriva egen
  * Utvärdera delarna, välj kul del
  * ---- planeras vidare då ----


## Loggbok

#### 2020-03-23

  Sett introdktionsfilmerna
  
  Börjat med bilprojektet genom att läsa igenom befintlig kod och försöka förstå
  
  Arbetat med pythonprojektet och valt ett miniprojekt
  
#### 2020-03-24

  Börjat på en egen Arduino kod
  
  Mekat med bilen för att försöka undvika att sladdar ramlar bort när den rör sig
  
#### 2020-03-27
  
  Arbetat med miniprojektet
  
#### 2020-03-31

  Pythonprojekt, fått första delen att fungera
  
  Fixat mqtt, kopplat bilen så att allt utom styrmekanismen fungerar med den färdiga koden. 
  
    ----CORONA M. MOTIVATIONSPROBLEM----
  
#### 2020-05-19

  Pythonprojektet är avklarat och inlämnat
  
  Bilen fungerar enligt färdigskriven kod och hemsidans design har förändrats något
  
#### 2020-06-01

  Tiden har lagts på att förstå den färdigskrivna koden
  
#### 2020-06-02

 Projektet är klart och inlämnat
