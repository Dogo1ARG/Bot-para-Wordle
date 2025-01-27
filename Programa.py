import os
import random


direccionScript = os.path.dirname(os.path.abspath(__file__))
os.chdir(direccionScript)


palabras = []

with open("Palabras_espanol.txt", 'r', encoding='utf-8') as diccionario:
    for linea in diccionario.readlines():
        if len(linea.strip()) == 5:
            palabras.append(linea.strip())



def adivinarLaPalabra(palabras, acierto, intento):
    nuevasPalabras = []
    for palabra in palabras:
        valido = True

        for i in range(5):
            if acierto[i] == 'B' and palabra[i] != intento[i]:
                valido = False
                break
            elif acierto[i] == 'I' and intento[i] in palabra:
                valido = False
                break
            elif acierto[i] == 'C' and (intento[i] not in palabra or palabra[i] == intento[i]):
                valido = False
                break
        if valido:
            nuevasPalabras.append(palabra)

    return nuevasPalabras
            




intento = random.choice(palabras)

for i in range(1, 7):
    print(f"Intento N°{i} palabra: {intento}")
    print("Responder: 'B', 'C' e 'I'")
    acierto = input("==> ").upper()

    if acierto == "BBBBB":
        print("Fin.")
        break

    palabras = adivinarLaPalabra(palabras, acierto, intento)

    intento = random.choice(palabras)

        


        

