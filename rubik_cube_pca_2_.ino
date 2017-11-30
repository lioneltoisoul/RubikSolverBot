/****************************************************************************************************
 * Code créer par Toisoul Lionel élève de robotique à la haute école de la ville de liège (ISET)
 * 2017/2018
 ****************************************************************************************************/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>    // Bibliothèque a télécharger sur adafruit 

// Utilisation de l'adresse par défaut 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Suivant le type de servo utilisé, la largeur d'impulsion minimale et maximale 
// peut changer. L'idéal est de sélectionner des valeurs aussi petites et aussi
// grande que possible sans jamais atteindre la butée de blocage du servo-moteur. 
// Vous aurrez peut-etre besoin de modifier ces valeurs pour les faire correspondrent 
// à votre type de servo!
#define SERVOMIN  150 // La longueur d'impulsion 'minimale' (valeur du compteur, max 4096)
#define SERVOMAX  600 // La longueur d'impulsion 'maximale' (valeur du compteur, max 4096)

// Servos Commandés - Numéro de sorties sur le PCA9685
uint8_t servoA = 0;
uint8_t servoa = 1;
uint8_t servoE = 2;
uint8_t servoe = 3;
uint8_t servoC = 4;
uint8_t servoc = 5;
uint8_t servoG = 6;
uint8_t servog = 7;


void setup() 
{
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Les servo sont mis-à-jour à ~60 Hz  //1000 max
}

/****************************************************************************************************
 *fonction sur le servo A
 ****************************************************************************************************/

void RentrerA (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 300, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoA, 0, longueurImpulsion);
}

void SortirA (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 105, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse
  pwm.setPWM(servoA, 0, longueurImpulsion);
}

void zeroA (void) //0degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 0, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoa, 0, longueurImpulsion);  
}

void nonanteA (void) //90degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 130, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoa, 0, longueurImpulsion);  
}

void fullA (void) //180 degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 270, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoa, 0, longueurImpulsion);  
}

/****************************************************************************************************
 *fonction sur le servo E
 ****************************************************************************************************/

void RentrerE (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 300, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoE, 0, longueurImpulsion);
}

void SortirE (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 95, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse
  pwm.setPWM(servoE, 0, longueurImpulsion);
}

void zeroE (void) //0degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 5, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoe, 0, longueurImpulsion);  
}

void nonanteE (void) //90degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 130, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoe, 0, longueurImpulsion);  
}

void fullE (void) //180 degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 260, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoe, 0, longueurImpulsion);  
}

/****************************************************************************************************
 *fonction sur le servo C
 ****************************************************************************************************/

void RentrerC (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 300, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoC, 0, longueurImpulsion);
}

void SortirC (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 140, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse
  pwm.setPWM(servoC, 0, longueurImpulsion);
}

void zeroC (void) //0degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 0, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoc, 0, longueurImpulsion);  
}

void nonanteC (void) //90degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 130, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoc, 0, longueurImpulsion);  
}

void fullC (void) //180 degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 260, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoc, 0, longueurImpulsion);  
}

/****************************************************************************************************
 *fonction sur le servo G
 ****************************************************************************************************/

void RentrerG (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 300, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servoG, 0, longueurImpulsion);
}

void SortirG (void)
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 190, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse
  pwm.setPWM(servoG, 0, longueurImpulsion);
}

void zeroG (void) //0degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 5, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servog, 0, longueurImpulsion);  
}

void nonanteG (void) //90degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 130, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servog, 0, longueurImpulsion);  
}

void fullG (void) //180 degré
{
  int longueurImpulsion =0;
  longueurImpulsion = map( 270, 0, 360, SERVOMIN, SERVOMAX);    // Transformation de degré en pulse 
  pwm.setPWM(servog, 0, longueurImpulsion);  
}



void loop() 
{
  int longueurImpulsion =0;
  int t=700; // delay entre chaques mouvements ne pas mettre <600
  
    if (Serial.available() > 0)   // Serial.available permet de recupérer les données envoyer sur le port serie de l'arduino
    {
      // On va décomposer les données recues en deux caractères distincts (car nous avons choisi de nommer toutes nos commandes par deux lettres)
      // On va utiliser A,B,C et D pour les quatres servos qui permettent de faire avancer les bras, 0 ou 1 en fonction de si ils sont sortis ou non
      // On va utiliser a,b,c et d pour les quatres servos qui permettent de faire tourner les bras, 0, 90 ou 180 en fonction du degré que l'on veut 
      // les faire tourner
      char c1 = Serial.read();
      delay(50);
      char c2 = Serial.read();   
      delay(50);

      
      switch(c1)
      {
        case 'A':
        if(c2 == '0')
        { 
          RentrerA();
          break;
        }
        if(c2 == '1')
        {
          SortirA();
          break;
        }
    
      case 'a':
        if(c2 == '2')
        { 
          zeroA();
          break;
        }
        else if (c2 == '3')
        {   
          nonanteA();
          break;
        }
        else if (c2 == '4')
        {
          fullA();
          break;
        }
      case 'E':
        if(c2 == '0')
        { 
          RentrerE();
          break;
        }
        if(c2 == '1')
        {
          SortirE();
          break;
        }
    
      case 'e':
        if(c2 == '2')
        { 
          zeroE();
          break;
        }
        else if (c2 == '3')
        {   
          nonanteE();
          break;
        }
        else if (c2 == '4')
        {
          fullE();
          break;
        }
      case 'C':
        if(c2 == '0')
        { 
          RentrerC();
          break;
        }
        if(c2 == '1')
        {
          SortirC();
          break;
        }
    
      case 'c':
        if(c2 == '2')
        { 
          zeroC();
          break;
        }
        else if (c2 == '3')
        {   
          nonanteC();
          break;
        }
        else if (c2 == '4')
        {
          fullC();
          break;
        }
      case 'G':
        if(c2 == '0')
        { 
          RentrerG();
          break;
        }
        if(c2 == '1')
        {
          SortirG();
          break;
        }
    
      case 'g':
        if(c2 == '2')
        { 
          zeroG();
          break;
        }
        else if (c2 == '3')
        {   
          nonanteG();
          break;
        }
        else if (c2 == '4')
        {
          fullG();
          break;
        }
      case 'X':
        if(c2 == 'X') //ouvre A et E et ferme C et G
        {
          RentrerA();
          RentrerE();
          RentrerC();
          RentrerG();
          zeroA();
          zeroE();
          zeroC();
          zeroG();
          break;
        }
        if(c2 == 'Y') //ferme tout les servos
        {
          SortirA();
          SortirE();
          SortirC();
          SortirG();
          break;

        }
      case 'P':
        if(c2 == '1')  //présente la face 1  (ROUGE)
        {   
          RentrerE();
          RentrerG();
          delay(t);
          nonanteE();
          nonanteG();
          delay(t);
          SortirE();
          SortirG();
          delay(t);
          RentrerA();
          RentrerC();
          delay(t);
          break;
        }
        if(c2 == '2')  //présente la face 2,3,4  (VERT)puis(ORANGE)puis(BLEU)
        {
          zeroG();
          fullE();
          delay(t);
          SortirA();
          SortirC();
          delay(t);
          RentrerG();
          RentrerE();
          delay(t);
          nonanteG();
          nonanteE();
          delay(t);
          SortirG();
          SortirE();
          delay(t);
          RentrerA();
          RentrerC();
          delay(t);
          break;

        }
        if(c2 == '3')  //présente la face 5 (JAUNE) 
        {
          zeroA();
          fullC();
          delay(t);
          zeroG();
          fullE();
          delay(t);
          SortirA();
          SortirC();
          delay(t);
          RentrerG();
          RentrerE();
          delay(t);
          nonanteA();
          nonanteC();
          delay(t);
          break;
        }
        if(c2 == '4')  //présente la face 6 (BLANC)  
        {
          zeroA();
          fullC();
          delay(t);
          SortirG();
          SortirE();
          delay(t);
          RentrerA();
          RentrerC();
          delay(t);
          nonanteA();
          nonanteC();
          delay(t);
          SortirA();
          SortirC();
          delay(t);
          RentrerG();
          RentrerE();
          delay(t);
          zeroA();
          fullC();
          delay(t);
          nonanteG();
          nonanteE();
          delay(t);
          SortirG();
          SortirE();
          delay(t);
          RentrerA();
          RentrerC();
          delay(t);
          break;
        }
        if(c2 == '5')  //remet le cube en position initial 
        {
          SortirA();
          SortirC();
          delay(t);
          RentrerG();
          RentrerE();
          delay(t);
          zeroG();
          zeroE();
          delay(t);
          nonanteA();
          nonanteC();
          delay(t);
          SortirG();
          SortirE();
          delay(t);
          RentrerA();
          RentrerC();
          delay(t);
          zeroA();
          zeroC();
          delay(t);
          SortirA();
          SortirC();
          delay(t);
          break;
        }
/****************************************************************************************************
 * Résolution face F
 ****************************************************************************************************/
        case 'F':
        if(c2 == '1')
        {
            RentrerE();
            delay(t);
            fullE();
            delay(t);
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            nonanteC();
            delay(t);
            RentrerC();
            delay(t);
            zeroC();
            delay(t);
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirA();
            SortirC();
            delay(t); 
            break;
        }
        if(c2 == '2')
        {
            RentrerE();
            delay(t);
            fullE();
            delay(t);
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            fullC();
            delay(t);
            RentrerC();
            delay(t);
            zeroC();
            delay(t);
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            break;
        }
        if(c2 == '3')
        {
            RentrerE();
            delay(t);
            fullE();
            delay(t);
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerC();
            delay(t);
            nonanteC();
            delay(t);
            SortirC();
            delay(t);
            zeroC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            break;
        }
/****************************************************************************************************
 * Résolution face R
 ****************************************************************************************************/
        case 'R':
        if(c2 == '1')
        {
           nonanteC();
           delay(t);
           RentrerC();
           delay(t);
           zeroC();
           delay(t);
           SortirC();
           delay(t);
           break;
        }
        if(c2 == '2')
        {
           fullC();
           delay(t);
           RentrerC();
           delay(t);
           zeroC();
           delay(t);
           SortirC();
           delay(t);
           break;
        }
        if(c2 == '3')
        {
           RentrerC();
           delay(t);
           nonanteC();
           delay(t);
           SortirC();
           delay(t);
           zeroC();
           delay(t);
           break;
        }
/****************************************************************************************************
 * Résolution face U
 ****************************************************************************************************/
        case 'U':
        if(c2 == '1')
        {
           nonanteE();
           delay(t);
           RentrerE();
           delay(t);
           zeroE();
           delay(t);
           SortirE();
           delay(t);
           break;
        }
        if(c2 == '2')
        {
           fullE();
           delay(t);
           RentrerE();
           delay(t);
           zeroE();
           delay(t);
           SortirE();
           delay(t);
           break;
        }
        if(c2 == '3')
        {
           RentrerE();
           delay(t);
           nonanteE();
           delay(t);
           SortirE();
           delay(t);
           zeroE();
           delay(t);
           break;
        }
/****************************************************************************************************
 * Résolution face L
 ****************************************************************************************************/
        case 'L':
        if(c2 == '1')
        {
           nonanteA();
           delay(t);
           RentrerA();
           delay(t);
           zeroA();
           delay(t);
           SortirA();
           delay(t);
           break;
        }
        if(c2 == '2')
        {
           fullA();
           delay(t);
           RentrerA();
           delay(t);
           zeroA();
           delay(t);
           SortirA();
           delay(t);
           break;
        }
        if(c2 == '3')
        {
           RentrerA();
           delay(t);
           nonanteA();
           delay(t);
           SortirA();
           delay(t);
           zeroA();
           delay(t);
           break;
        }
/****************************************************************************************************
 * Résolution face B
 ****************************************************************************************************/
        case 'B':
        if(c2 == '1')
        {
            RentrerE();
            delay(t);
            fullE();
            delay(t);
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            nonanteA();
            delay(t);
            RentrerA();
            delay(t);
            zeroA();
            delay(t);
            SortirA();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            break;
        }
        if(c2 == '2')
        {
            RentrerE();
            delay(t);
            fullE();
            delay(t);
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            fullA();
            delay(t);
            RentrerA();
            delay(t);
            zeroA();
            delay(t);
            SortirA();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            break;
        }
        if(c2 == '3')
        {
            RentrerE();
            delay(t);
            fullE();
            delay(t);
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerA();
            delay(t);
            nonanteA();
            delay(t);
            SortirA();
            delay(t);
            zeroA();
            delay(t);
            RentrerG();
            RentrerE();
            delay(t);
            nonanteG();
            nonanteE();
            delay(t);
            SortirG();
            SortirE();
            delay(t);
            RentrerA();
            RentrerC();
            delay(t);
            zeroG();
            fullE();
            delay(t);
            SortirA();
            SortirC();
            delay(t);
            break;
        }
/****************************************************************************************************
 * Résolution face D
 ****************************************************************************************************/
        case 'D':
        if(c2 == '1')
        {
           nonanteG();
           delay(t);
           RentrerG();
           delay(t);
           zeroG();
           delay(t);
           SortirG();
           break;
        }
        if(c2 == '2')
        {
           fullG();
           delay(t);
           RentrerG();
           delay(t);
           zeroG();
           delay(t);
           SortirG();
           break;
        }
        if(c2 == '3')
        {
           RentrerG();
           delay(t);
           nonanteG();
           delay(t);
           SortirG();
           delay(t);
           zeroG();
           delay(t);
           break;
        }
      }
     }
}
