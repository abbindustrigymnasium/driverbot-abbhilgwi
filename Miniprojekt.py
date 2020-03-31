import time

ett=0
x=0
två=0

def svar(val,alternativ):
    global ett
    global två
    global x
    if val == alternativ:
        if alternativ=="1":
            ett += 1
        elif alternativ=="2":
            två += 1
        elif alternativ== "X" or "x":
            x += 1

print("- "*18,"\n","-"*32,"\n Välkommen till Frågande Frukten!","\n","-"*32,"\n","*"*32,"\n","*"*7," "*6,"*"*7," ","*"*7,"\n","*"*6," ","*"*4," ","*"*6," ","*"*7, "\n","*"*12," ","*"*7," ","*"*7,"\n","*"*11," ","*"*8," ","*"*7,"\n","*"*10," ","*"*9," ","*"*7,"\n","*"*9," ","*"*10," ","*"*7,"\n","*"*32,"\n","*"*9," ","*"*10," ","*"*7,"\n","*"*32,"\n","-"*32,"\n"," "*7,"Vill du spela?!","\n"," "*6,"~"*17,"\n"," "*7,">Ja"," "*6,">Nej","\n","-"*32)
a=input(">").upper()



try:
    if a == "JA":
        print("Vad vill du spela?","\n a) 'Min inre frukt'" "\n b) 'Fruktastiska frågor'","\n \n Skriv 'a' eller 'b'")
        d =input(">").upper()
        if d == "A":
            print("Vad frukt-ansvärt roligt!","\n Här kommer spelet;")
            time.sleep(1)
            
            print("\n \n","Vad stämmer bäst in på dig?")
            print("\n","En varm sommardag föredrar jag...","\n","1) att ligga ute och jäsa i solen","\n X) att vara innomhus i den sköna skuggan","\n 2) att ligga i (jord)källaren och vänta på bättre tider")
            b=input("\n >").upper()
            svar(b,"1")
            svar(b,"X")
            svar(b,"2")
            
            print("\n","\n","Jag tycker bäst om","\n","1) klara, starka färger som syns!","\n X) färger som inte är så uppseendeväckande, fast fortfarande färger","\n 2) svart. Eller andra jordnära färger som smälter in")
            b=input("\n >").upper()
            svar(b,"1")
            svar(b,"X")
            svar(b,"2")

            print("\n","\n","Jag är för det mesta...","\n","1) explosiv! Bäst att ta chansen när den kommer","\n X) smart. Jag prioriterar mina resurser så att de ska räcka länge","\n 2) obrydd. Det brukar aldrig vara något problem att räcka till")
            b=input("\n >").upper()
            svar(b,"1")
            svar(b,"X")
            svar(b,"2")

            print("\n","\n","Andra beskriver ofta mig som...","\n","1) speciell. Antingen älskar man mig eller så avskyr man mig","\n X) ok. Ingen brukar ha någon speciell åsikt men ingen verka tycka illa om mig heller","\n 2) ... Vilka andra? Folk brukar inte vara med mig om de inte måste")
            b=input("\n >").upper()
            svar(b,"1")
            svar(b,"X")
            svar(b,"2")

            print("\n","\n","Mitt ego säger att jag är...","\n","1) söt!","\n X) ofta rätt sur...","\n 2) meh")
            b=input("\n >").upper()
            svar(b,"1")
            svar(b,"X")
            svar(b,"2")

            print("\n","\n","Jag är...","\n","1) självsäker! Jag vet vem jag är och är nöjd med det","\n X) ... ingen aning....","\n 2) inte direkt osäker... Men jag föredrar om jag inte syns")
            b=input("\n >").upper()
            svar(b,"1")
            svar(b,"X")
            svar(b,"2")

            print("\n","\n","Folk brukar kalla mig...","\n","1) olika smeknamn. Jag är så speciell att de inte kan bestämma sig","\n X) mitt namn?.. Vad annars?","\n 2) En hel del saker som inte ska talas öppet om.. Jag blir ofta asocierad med andra.. mindre trevliga.. typer")
            b=input("\n >").upper()
            svar(b,"1")
            svar(b,"X")
            svar(b,"2")

            print(ett,x,två)
        
        elif d == "B":
            print("under constraction")

        else:
            raise KeyboardInterrupt


    elif a == "NEJ":
        print("Nej! Vad synd :(","\n","Säg bara till om du ångrar dig...")
        time.sleep(1)
        print("\n","\n","Den gröna knappen")
        time.sleep(2)
        print("\n","\n","Där uppe!")
        time.sleep(1)
        print("\n","Till höger!")
        time.sleep(2)
        print("\n","ok...")
        time.sleep(0.5)
        print("...fattar vinken")
        time.sleep(0.5)
        print("\n","\n")
    
    else:
        raise KeyboardInterrupt

except KeyboardInterrupt:
    print("Jag tror du missförstod...","\n","Försök igen med den gröna knappen")



