#include <Adafruit_NeoPixel.h>
#include <WiiChuck.h>
/*****************************************/
/*****************************************/
//**********GLOBALE VARIABLEN************//
/*****************************************/
/*****************************************/

//Integration Wii NUNCHUK
//https://www.makerblog.at/2016/01/wii-nunchuk-controller-am-arduino-teil-1/
//https://learn.adafruit.com/adafruit-wii-nunchuck-breakout-adapter/arduino-use
//https://github.com/madhephaestus/WiiChuck/blob/master/src/Nunchuck.h  
//

//**NUNCHUCKS**//
Accessory nunchuck1;
Accessory nunchuck2;
Accessory nunchuck3;
Accessory nunchuck4;
/*****************************************/



/*****************************************/

//**HELLIGKEITS EINSTELLUNG GLOBAL**//
int brght = 170;


/****************************************/

//**PIN-BELEGUNG SPIELER**//
int player_one = 2;
int player_x_one = A0;
int player_y_one = A1;
int player_two = 3;
int player_x_two = A2;
int player_y_two = A3;
int player_three = 4;
int player_x_three = A4;
int player_y_three = A5;
int player_four = 5;
int player_x_four = A6;
int player_y_four = A7;
//**PIN-BELEGUNG**//
int LED_PIN = 6;
int PIN_AUDIO = 36;


/****************************************/

//**LAUFLICHT**//
int n = 96;


/***************************************/

//**NUMMER DER LEDS UND TIMER FUNKTION FÜR STANDBY-MODUS**//
int MAXLED = 2304;
int long standby_Timer = 0;
int long st = 3000;  // gibt an wann der standby-Modus beginnt nicht zu groß machen!!


/*************************************/

//**VARIABLEN ZUR SPIEL AUSWAHL UND ZUM RESET**//
int select = 0;  // select muss zum start 0 sein, bis jetzt select 0 bis 6 belegt!!
int select_input = 12;
int x_one;
int y_one;
int x_two;
int y_two;
int x_three;
int y_three;
int x_four;
int y_four;
int courser_on_TIC_TAC_TOE = false;
int courser_on_RACE_GAME = false;
int courser_on_COIN_GAME = false;
int courser_on_JUMP_AND_RUN = false;
int courser_on_STOP_AND_GO = true;
int x_reset = 0;
int y_reset = 0;
/************************************/

//**RACE GAME**//
int TBEEP = 3;

int run = 0;

float speed1 = 0;
float speed2 = 0;
float speed3 = 0;
float speed4 = 0;
float dist1 = 9216;
float dist2 = 9216;
float dist3 = 9216;
float dist4 = 9216;

byte loop1 = 5;
byte loop2 = 5;
byte loop3 = 5;
byte loop4 = 5;

byte leader = 0;
byte loop_max = 5;  //Rundenanzahl

float ACEL = 4.5;
float kf = 0.20;

byte flag_sw1 = 0;
byte flag_sw2 = 0;
byte flag_sw3 = 0;
byte flag_sw4 = 0;
byte draworder = 0;

unsigned long timestamp = 0;
int tdelay = 1;
int race_win_delay = 1000;


/******************************/

//**TIC TAC TOE**//
int grid1 = 16;
int grid2 = 32;
int grid3 = 768;
int grid4 = 1536;

int select_beginner;
bool beginner;

int ttt_start = 0;

//**PLAYER X**//
bool a1_used1 = false;
bool a2_used1 = false;
bool a3_used1 = false;
bool b1_used1 = false;
bool b2_used1 = false;
bool b3_used1 = false;
bool c1_used1 = false;
bool c2_used1 = false;
bool c3_used1 = false;
//**PLAYER O**//
bool a1_used2 = false;
bool a2_used2 = false;
bool a3_used2 = false;
bool b1_used2 = false;
bool b2_used2 = false;
bool b3_used2 = false;
bool c1_used2 = false;
bool c2_used2 = false;
bool c3_used2 = false;

int x_achse;
int y_achse;
int x = 1;
int y = 1;

int status = 0;
int status_pressed;
int status_pressed1;

bool player_x_win = false;
bool player_o_win = false;
bool no_winner = false;

int count_no_winner = 0;


/******************************/

//**COIN COLLECT**//
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int ran = 0;
int ran2 = 0;
int ran_power_up = 0;
int game = 1;
int score1 = 0;
int score2 = 0;
int score3 = 0;
int score4 = 0;
int countcoin_ran = 10;
int countcoin_ran2 = 10;
int dotnew = 10;



/*****************************/

//**JUMP AND RUN**//
bool new_block = true;
int ran_num = 0;
int led_row1 = 0;
int led_row2 = 0;
int led_row3 = 0;
int led_row4 = 0;
int led_row5 = 0;
int num_of_total_rows = 0;
bool row1 = false;
bool row2 = false;
bool row3 = false;
bool row4 = false;
bool row5 = false;
int jump1 = 0;
int jump2 = 0;
int jump3 = 0;
int move1 = 0;
int move2 = 0;
int move3 = 0;
int check_for_double = 0;
int row_speed = 18;
int row_move_speed = 1;
int counter_new_row = 0;
bool coll_detect_one = false;
int coll_detect_two = 0;
int coll_detect_three = 0;
int coll_detect_four = 0;
int coll_detect_five = 0;
bool win_row_one = false;
bool win_row_two = false;
bool win_row_three = false;
bool blackout_time = false;
int blackout_count = 0;
/*****************************/


/****************************/

//**SQUID GAME**//
int ran_timer1 = 0;
int ran_timer2 = 0;
int ran_timer3 = 0;
bool green_allow_to_run = true;
bool yellow_allow_to_run = false;
bool red_not_allow_to_run = false;
bool green = true;
bool yellow = false;
bool red = false;
int move_squid_p1 = 0;
int check_for_move1 = 0;
int move_squid_p2 = 0;
int check_for_move2 = 0;
int move_squid_p3 = 0;
int check_for_move3 = 0;
int move_squid_p4 = 0;
int check_for_move4 = 0;
bool failure_p1 = false;
bool failure_p2 = false;
bool failure_p3 = false;
bool failure_p4 = false;
bool win_p1 = false;
bool win_p2 = false;
bool win_p3 = false;
bool win_p4 = false;
int move_speed = 3;
/**************************/

/*************************/
//**FOLLOW PATH**//
int follow_direction = 0;
int length = 0;
int max_path_length = 200;
int start_position = 100;
int ran_path_num = 0;

/***********************/


//**Easter EGG**//
int easter_counter = 0;


Adafruit_NeoPixel led(MAXLED, LED_PIN, NEO_GRB + NEO_KHZ800);  // Wird benötigt um die Adafruit Library (#include <Adafruit_NeoPixel.h>) zu benutzen...https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html



/****************************/
//Setup aller input und Output Pins des Arduinos
void setup() {
  Serial.begin(9600);
  led.begin();
  for (int i = 0; i < MAXLED; i++) {
    led.setPixelColor(i, led.Color(0, 0, 0));
  }
  led.show();
  pinMode(player_one, INPUT_PULLUP);
  pinMode(player_x_one, INPUT_PULLUP);
  pinMode(player_y_one, INPUT_PULLUP);
  pinMode(player_two, INPUT_PULLUP);
  pinMode(player_x_two, INPUT_PULLUP);
  pinMode(player_y_two, INPUT_PULLUP);
  pinMode(player_three, INPUT_PULLUP);
  pinMode(player_x_three, INPUT_PULLUP);
  pinMode(player_y_three, INPUT_PULLUP);
  pinMode(player_four, INPUT_PULLUP);
  pinMode(player_x_four, INPUT_PULLUP);
  pinMode(player_y_four, INPUT_PULLUP);
  pinMode(select_input, INPUT_PULLUP);
  randomSeed(analogRead(A15));
  led.setBrightness(brght);
  //Zur Port auswahl am Arduino/Multiplexer
  nunchuck1.addMultiplexer(0x70,0);
  nunchuck2.addMultiplexer(0x70,1);
  nunchuck3.addMultiplexer(0x70,2);
  nunchuck4.addMultiplexer(0x70,3);
  //
  nunchuck1.begin();
  nunchuck2.begin();
  nunchuck3.begin();
  nunchuck4.begin();
  //Wenn die Automatische erkennung Fehlerhaft ist
  if (nunchuck1.type == Unknown) {
		nunchuck1.type = NUNCHUCK;
	}
	if (nunchuck2.type == Unknown) {
		nunchuck2.type = NUNCHUCK;
	}
  if (nunchuck3.type == Unknown) {
		nunchuck3.type = NUNCHUCK;
	}
	if (nunchuck4.type == Unknown) {
		nunchuck4.type = NUNCHUCK;
	}
}


void start_screen() {
  for (int i = 0; i < MAXLED; i++) {  //Home Rot
    if (i == 1064 || i == 1281 || i == 1263 || i == 268 || i == 1988 || i == 1939 || i == 1892 || i == 1941 || i == 1033 || i == 1032 || i == 1031 || i == 985 || i == 984 || i == 983 || i == 937 || i == 936 || i == 935 || i == 889 || i == 888 || i == 887 || i == 841 || i == 840 || i == 839 || i == 793 || i == 792 || i == 791 || i == 744 || i == 696 || i == 648 || i == 1178 || i == 1177 || i == 1176 || i == 1175 || i == 1174 || i == 1130 || i == 1129 || i == 1128 || i == 1127 || i == 1126 || i == 1082 || i == 1081 || i == 1080 || i == 1079 || i == 1078 || i == 1271 || i == 1270 || i == 1223 || i == 1222 || i == 1274 || i == 1273 || i == 1226 || i == 1225 || i == 1323 || i == 1322 || i == 1318 || i == 1317 || i == 1269 || i == 1268 || i == 1267 || i == 1277 || i == 1276 || i == 1275 || i == 1233 || i == 1232 || i == 1231 || i == 1230 || i == 1229 || i == 1219 || i == 1218 || i == 1217 || i == 1216 || i == 1215 || i == 1184 || i == 1183 || i == 1135 || i == 1169 || i == 1168 || i == 1121 || i == 1329 || i == 1328 || i == 1376 || i == 1375 || i == 1374 || i == 1422 || i == 1421 || i == 1420 || i == 1419 || i == 1418 || i == 1417 || i == 1416 || i == 1415 || i == 1414 || i == 1413 || i == 1412 || i == 1411 || i == 1410 || i == 1362 || i == 1361 || i == 1360 || i == 1312 || i == 1311 || i == 1467 || i == 1466 || i == 1465 || i == 1464 || i == 1463 || i == 1462 || i == 1461) {
      led.setPixelColor(i - 1, led.Color(255, 0, 0));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home Weiß
    if (i == 1208 || i == 1207 || i == 1206 || i == 1205 || i == 1204 || i == 1203 || i == 1202 || i == 1157 || i == 1109 || i == 1107 || i == 1059 || i == 1016 || i == 1015 || i == 1014 || i == 1013 || i == 1012 || i == 1011 || i == 1010 || i == 918 || i == 869 || i == 820 || i == 776 || i == 775 || i == 774 || i == 773 || i == 772 || i == 771 || i == 724 || i == 677 || i == 630 || i == 107 || i == 813 || i == 2076 || i == 812 || i == 811 || i == 810 || i == 809 || i == 808 || i == 807 || i == 860 || i == 907 || i == 954 || i == 764 || i == 715 || i == 666 || i == 2045 || i == 2044 || i == 2043 || i == 2042 || i == 2041 || i == 2040 || i == 2039 || i == 2038 || i == 2037 || i == 2036 || i == 2035 || i == 1853 || i == 1852 || i == 1851 || i == 1850 || i == 1849 || i == 1848 || i == 1847 || i == 1846 || i == 1845 || i == 1844 || i == 1843 || i == 1994 || i == 1946 || i == 1898 || i == 1990 || i == 1942 || i == 1894 || i == 1798 || i == 1750 || i == 1702 || i == 1802 || i == 1754 || i == 1706 || i == 2182 || i == 2134 || i == 2086 || i == 2186 || i == 2138 || i == 2090 || i == 2028 || i == 1980 || i == 1932 || i == 1884 || i == 1836 || i == 1788 || i == 2027 || i == 1978 || i == 1929 || i == 2029 || i == 1982 || i == 1935 || i == 395 || i == 347 || i == 299 || i == 251 || i == 203 || i == 155 || i == 154 || i == 201 || i == 248 || i == 156 || i == 205 || i == 254 || i == 79 || i == 78 || i == 77 || i == 76 || i == 75 || i == 74 || i == 73 || i == 72 || i == 71 || i == 70 || i == 69 || i == 68 || i == 67 || i == 66 || i == 65 || i == 64 || i == 63 || i == 62 || i == 163 || i == 162 || i == 115 || i == 114 || i == 167 || i == 166 || i == 119 || i == 118) {
      led.setPixelColor(i - 1, led.Color(brght * 0.5, brght * 0.5, brght * 0.5));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home Blau
    if (i == 1991 || i == 1993 || i == 1897 || i == 1944 || i == 1895 || i == 357 || i == 309) {
      led.setPixelColor(i - 1, led.Color(0, 0, 255));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home räder auto
    if (i == 163 || i == 162 || i == 115 || i == 114 || i == 167 || i == 119 || i == 166 || i == 118) {
      led.setPixelColor(i - 1, led.Color(brght, brght, brght));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home Gelb
    if (i == 260 || i == 1191 || i == 1143 || i == 1095 || i == 1050 || i == 1049 || i == 1048 || i == 1242 || i == 1241 || i == 1240 || i == 1195 || i == 1147 || i == 1099) {
      led.setPixelColor(i - 1, led.Color(255, 255, 0));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home dimm Gelb
    if (i == 1194 || i == 1193 || i == 1192 || i == 1146 || i == 1145 || i == 1144 || i == 1098 || i == 1097 || i == 1096) {
      led.setPixelColor(i - 1, led.Color(100, 100, 0));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home Grün
    if (i == 362 || i == 361 || i == 360 || i == 359 || i == 358 || i == 314 || i == 313 || i == 312 || i == 311 || i == 310 || i == 266 || i == 265 || i == 264 || i == 263 || i == 262 || i == 218 || i == 217 || i == 216 || i == 215 || i == 214 || i == 261 || i == 213 || i == 212 || i == 315 || i == 267 || i == 219 || i == 220) {
      led.setPixelColor(i - 1, led.Color(0, 255, 0));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home strasse weiß
    if (i == 63 || i == 79 || i == 78 || i == 77 || i == 76 || i == 75 || i == 74 || i == 73 || i == 72 || i == 71 || i == 70 || i == 69 || i == 68 || i == 67 || i == 66 || i == 65 || i == 64 || i == 63 || i == 81 || i == 80) {
      led.setPixelColor(i - 1, led.Color(255, 255, 255));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home weiß stop and go
    if (i == 1673 || i == 1722 || i == 1771 || i == 1820 || i == 1869 || i == 1725 || i == 1773 || i == 1821 || i == 1868 || i == 1867 || i == 1866 || i == 1859 || i == 1860 || i == 1861 || i == 1862 || i == 1907 || i == 1910 || i == 1955 || i == 1958 || i == 2003 || i == 2004 || i == 2005 || i == 2006 || i == 2099 || i == 2100 || i == 2101 || i == 2102 || i == 2147 || i == 2150 || i == 2196 || i == 2197) {
      led.setPixelColor(i, led.Color(255, 255, 255));
    }
  }
  for (int i = 0; i < MAXLED; i++) {  //Home blau stop and go
    if (i == 1716 || i == 1717 || i == 1811 || i == 1814 || i == 1908 || i == 1909 || i == 2148 || i == 2149 || i == 2195 || i == 2198 || i == 2243 || i == 2246 || i == 2292 || i == 2293) {
      led.setPixelColor(i, led.Color(0, 0, 100));
    }
  }
  led.show();
}


//RUFT STANDBY BILDSCHIRM, SOWIE RESET UND DEN START BILDSCHIRM//
void start_program() {
  if (standby_Timer > st) {
    select = 10;  // select wird auf einen wert gesetzt der noch nicht in der Spielauswahl verwendet wurde (der Wert an sich ist für die Funktion der runlight function egal)
    runlight();
    reset();
  }
  if (select == 0) {
    start_screen();
    easter_egg();
    reset();
  }
}
//

//SPIELAUSWAHL UND ZURÜCK ZUM START BILDSCHIRM//
void reset() {
  nunchuck1.readData();
  nunchuck2.readData();
  nunchuck3.readData();
  nunchuck4.readData();
  int digital_input = digitalRead(select_input);
  if (easter_counter < 100) {
    if (digital_input == 1 && select != 0) {
      for (int i = 0; i < MAXLED; i++) {
        led.setPixelColor(i, led.Color(0, 0, 0));
      }
      led.show();
      select = 0;
      standby_Timer = 0;
    }
    if (select == 0) {
      x_one = nunchuck1.getJoyX();
      y_one = nunchuck1.getJoyY();
      x_two = nunchuck2.getJoyX();
      y_two = nunchuck2.getJoyY();
      x_three = nunchuck3.getJoyX();
      y_three = nunchuck3.getJoyY();
      x_four = nunchuck4.getJoyX();
      y_four = nunchuck4.getJoyY();

      //RACE GAME//
      if (y_one == 0 || y_two == 0 || y_three == 0 || y_four == 0 || courser_on_RACE_GAME) {
        courser_on_TIC_TAC_TOE = false;
        courser_on_RACE_GAME = true;
        courser_on_COIN_GAME = false;
        courser_on_JUMP_AND_RUN = false;
        courser_on_STOP_AND_GO = false;
        for (int i = 60; i < 396; i++) {
          led.setPixelColor(i, led.Color(0, 0, 0));
        }
        led.show();
        if (nunchuck1.getButtonZ() == 1 || nunchuck2.getButtonZ()  == 1 || nunchuck3.getButtonZ()  == 1 || nunchuck4.getButtonZ()  == 1) {
          select = 1;
          standby_Timer = 0;
        }
      }
      //TIC TAC TOE//
      if (y_one == 255 || y_two == 255 || y_three == 255 || y_four == 255 || courser_on_TIC_TAC_TOE) {
        courser_on_TIC_TAC_TOE = true;
        courser_on_RACE_GAME = false;
        courser_on_COIN_GAME = false;
        courser_on_JUMP_AND_RUN = false;
        courser_on_STOP_AND_GO = false;
        for (int i = 1701; i < 2187; i++) {
          led.setPixelColor(i, led.Color(0, 0, 0));
        }
        led.show();
        if (nunchuck1.getButtonZ() == 1 || nunchuck2.getButtonZ()  == 1 || nunchuck3.getButtonZ()  == 1 || nunchuck4.getButtonZ()  == 1) {
          select = 2;
          standby_Timer = 0;
        }
      }
      //COIN GAME//
      if (x_one == 0 || x_two == 0 || x_three == 0 || x_four == 0 || courser_on_COIN_GAME) {
        courser_on_TIC_TAC_TOE = false;
        courser_on_RACE_GAME = false;
        courser_on_COIN_GAME = true;
        courser_on_JUMP_AND_RUN = false;
        courser_on_STOP_AND_GO = false;
        for (int i = 664; i < 1243; i++) {
          if (i == 665 || i == 763 || i == 714 || i == 665 || i == 859 || i == 906 || i == 953 || i == 666 || i == 715 || i == 764 || i >= 806 && i <= 813 || i == 860 || i == 907 || i == 954 || i >= 1047 && i <= 1051 || i >= 1094 && i <= 1100 || i >= 1142 && i <= 1148 || i >= 1190 && i <= 1196 || i >= 1239 && i <= 1243) {
            led.setPixelColor(i, led.Color(0, 0, 0));
          }
        }
        led.show();
        if (nunchuck1.getButtonZ() == 1 || nunchuck2.getButtonZ()  == 1 || nunchuck3.getButtonZ()  == 1 || nunchuck4.getButtonZ()  == 1) {
          select = 3;
          standby_Timer = 0;
        }
      }
      //JUMP AND RUN//
      if (x_one == 255 || x_two == 255 || x_three == 255 || x_four == 255 || courser_on_JUMP_AND_RUN) {
        courser_on_TIC_TAC_TOE = false;
        courser_on_RACE_GAME = false;
        courser_on_COIN_GAME = false;
        courser_on_JUMP_AND_RUN = true;
        courser_on_STOP_AND_GO = false;
        for (int i = 629; i < 1210; i++) {
          if (i >= 1201 && i <= 1209 || i >= 1156 && i <= 1158 || i >= 1106 && i <= 1110 || i >= 1058 && i <= 1065 || i >= 1009 && i <= 1017 || i >= 917 && i <= 919 || i >= 868 && i <= 870 || i >= 819 && i <= 821 || i >= 770 && i <= 777 || i >= 723 && i <= 725 || i >= 676 && i <= 678 || i >= 629 && i <= 631) {
            led.setPixelColor(i, led.Color(0, 0, 0));
          }
        }
        led.show();
        if (nunchuck1.getButtonZ() == 1 || nunchuck2.getButtonZ()  == 1 || nunchuck3.getButtonZ()  == 1 || nunchuck4.getButtonZ()  == 1) {
          select = 4;
          standby_Timer = 0;
        }
      }
      //STOP AND GO//
      //überprüfen
      if (y_one >= 220 && x_one <= 15 && x_one >= 5 || y_two >= 220 && x_two <= 15 && x_two >= 5 || y_three >= 220 && x_three <= 15 && x_three >= 5  || y_four >= 220 && x_four <= 15 && x_four >= 5 ) {
        courser_on_TIC_TAC_TOE = false;
        courser_on_RACE_GAME = false;
        courser_on_COIN_GAME = false;
        courser_on_JUMP_AND_RUN = false;
        courser_on_STOP_AND_GO = true;
        for (int i = 0; i < MAXLED; i++) {  //Home weiß stop and go
          if (i == 1716 || i == 1717 || i == 1811 || i == 1814 || i == 1908 || i == 1909 || i == 2148 || i == 2149 || i == 1673 || i == 1722 || i == 1771 || i == 1820 || i == 1869 || i == 1725 || i == 1773 || i == 1821 || i == 1868 || i == 1867 || i == 1866 || i == 1859 || i == 1860 || i == 1861 || i == 1862 || i == 1907 || i == 1910 || i == 1955 || i == 1958 || i == 2003 || i == 2004 || i == 2005 || i == 2006 || i == 2099 || i == 2100 || i == 2101 || i == 2102 || i == 2147 || i == 2150 || i == 2196 || i == 2197) {
            led.setPixelColor(i, led.Color(0, 0, 0));
          }
        }
      }
      if (nunchuck1.getButtonZ() == 1 || nunchuck2.getButtonZ()  == 1) {
        select = 5;
        standby_Timer = 0;
      }
    }
  }
}
//



//STANDBY-MODUS LAUFLICHT//
void runlight() {
  for (int i = 0; i < MAXLED; i++) {
    led.setPixelColor(i, led.Color(0, 0, 0));
  }
  for (int i = 0; i < MAXLED; i++) {
    led.setPixelColor(i, led.Color(brght * 0.2, brght * 0.2, brght * 0.2));
  }
  for (int i = 0; i < MAXLED; i++) {
    if (i == 1773 || i == 1772 || i == 1771 || i == 1770 || i == 1769 || i == 1768 || i == 1767 || i == 1766 || i == 1725 || i == 1724 || i == 1723 || i == 1722 || i == 1721 || i == 1720 || i == 1719 || i == 1718 || i == 1674 || i == 1673 || i == 1626 || i == 1625 || i == 1578 || i == 1577 || i == 1530 || i == 1529 || i == 1482 || i == 1481 || i == 1434 || i == 1433 || i == 1386 || i == 1385 || i == 1338 || i == 1337 || i == 1290 || i == 1289 || i == 1242 || i == 1241 || i == 1194 || i == 1193 || i == 1146 || i == 1145 || i == 1098 || i == 1097 || i == 1050 || i == 1049 || i == 1002 || i == 1001 || i == 954 || i == 953 || i == 1763 || i == 1762 || i == 1715 || i == 1714 || i == 1667 || i == 1666 || i == 1619 || i == 1618 || i == 1571 || i == 1570 || i == 1523 || i == 1522 || i == 1475 || i == 1474 || i == 1427 || i == 1426 || i == 1379 || i == 1378 || i == 1331 || i == 1330 || i == 1283 || i == 1282 || i == 1235 || i == 1234 || i == 1187 || i == 1186 || i == 1139 || i == 1138 || i == 1091 || i == 1090 || i == 1043 || i == 1042 || i == 995 || i == 994 || i == 947 || i == 946 || i == 1761 || i == 1760 || i == 1759 || i == 1713 || i == 1712 || i == 1711 || i == 1377 || i == 1376 || i == 1375 || i == 1329 || i == 1328 || i == 1327 || i == 993 || i == 992 || i == 991 || i == 945 || i == 944 || i == 943 || i == 1660 || i == 1659 || i == 1612 || i == 1611 || i == 1564 || i == 1563 || i == 1516 || i == 1515 || i == 1468 || i == 1467 || i == 1420 || i == 1419 || i == 1273 || i == 1272 || i == 1225 || i == 1224 || i == 1177 || i == 1176 || i == 1129 || i == 1128 || i == 1081 || i == 1080 || i == 1033 || i == 1032 || i == 988 || i == 987 || i == 986 || i == 985 || i == 984 || i == 940 || i == 939 || i == 938 || i == 937 || i == 936 || i == 1372 || i == 1371 || i == 1370 || i == 1369 || i == 1368 || i == 1324 || i == 1323 || i == 1322 || i == 1321 || i == 1320 || i == 1756 || i == 1755 || i == 1754 || i == 1753 || i == 1752 || i == 1708 || i == 1707 || i == 1706 || i == 1705 || i == 1704 || i == 1749 || i == 1748 || i == 1701 || i == 1700 || i == 1653 || i == 1652 || i == 1605 || i == 1604 || i == 1557 || i == 1556 || i == 1509 || i == 1508 || i == 1461 || i == 1460 || i == 1413 || i == 1412 || i == 1365 || i == 1364 || i == 1317 || i == 1316 || i == 1269 || i == 1268 || i == 1221 || i == 1220 || i == 1173 || i == 1172 || i == 1125 || i == 1124 || i == 1077 || i == 1076 || i == 1029 || i == 1028 || i == 981 || i == 980 || i == 933 || i == 932 || i == 979 || i == 978 || i == 977 || i == 931 || i == 930 || i == 929 || i == 1742 || i == 1741 || i == 1694 || i == 1693 || i == 1646 || i == 1645 || i == 1598 || i == 1597 || i == 1550 || i == 1549 || i == 1502 || i == 1501 || i == 1454 || i == 1453 || i == 1406 || i == 1405 || i == 1358 || i == 1357 || i == 1310 || i == 1309 || i == 1262 || i == 1261 || i == 1214 || i == 1213 || i == 1166 || i == 1165 || i == 1118 || i == 1117 || i == 1070 || i == 1069 || i == 1022 || i == 1021 || i == 974 || i == 973 || i == 926 || i == 925 || i == 1736 || i == 1735 || i == 1688 || i == 1687 || i == 1640 || i == 1639 || i == 1592 || i == 1591 || i == 1544 || i == 1543 || i == 1496 || i == 1495 || i == 1448 || i == 1447 || i == 1400 || i == 1399 || i == 1352 || i == 1351 || i == 1304 || i == 1303 || i == 1256 || i == 1255 || i == 1208 || i == 1207 || i == 1160 || i == 1159 || i == 1112 || i == 1111 || i == 1064 || i == 1063 || i == 1016 || i == 1015 || i == 968 || i == 967 || i == 920 || i == 919 || i == 1740 || i == 1739 || i == 1738 || i == 1737 || i == 1692 || i == 1691 || i == 1690 || i == 1689 || i == 1356 || i == 1355 || i == 1354 || i == 1353 || i == 1308 || i == 1307 || i == 1306 || i == 1305) {
      led.setPixelColor(i - n, led.Color(255, 0, 0));
    }
  }
  n--;
  led.show();
  if (n <= 0) {
    n = 96;
  }
  easter_counter = 0;
}
//


//RACE GAME FUNKTIONEN ZUM ANZEIGEN DER SPIELER POSITIONEN//
//WIRD IN DER MAIN FUNCTION AUFGERUFEN//
void draw_car1(void) {
  for (int i = 0; i <= loop1; i++) {
    led.setPixelColor((word)dist1 % MAXLED + i, led.Color(255, 0, 0));
  }
}
void draw_car2(void) {
  for (int i = 0; i <= loop2; i++) {
    led.setPixelColor(((word)dist2 % MAXLED) + i, led.Color(0, 255, 0));
  }
}
void draw_car3(void) {
  for (int i = 0; i <= loop1; i++) {
    led.setPixelColor(((word)dist3 % MAXLED) + i, led.Color(0, 0, 255));
  }
}
void draw_car4(void) {
  for (int i = 0; i <= loop2; i++) {
    led.setPixelColor(((word)dist4 % MAXLED) + i, led.Color(255, 255, 255));
  }
}
//

//TIC TAC TOE FUNKTIONEN//
void check_no_winner() {
  if (count_no_winner >= 9 && !player_x_win && !player_o_win) {
    no_winner = true;
  }
}
void check_win_tic_tac_toe() {
  //PLAYER X
  if (a1_used1 && a2_used1 && a3_used1) {
    player_x_win = true;
  }
  if (b1_used1 && b2_used1 && b3_used1) {
    player_x_win = true;
  }
  if (c1_used1 && c2_used1 && c3_used1) {
    player_x_win = true;
  }
  if (a1_used1 && b1_used1 && c1_used1) {
    player_x_win = true;
  }
  if (a2_used1 && b2_used1 && c2_used1) {
    player_x_win = true;
  }
  if (a3_used1 && b3_used1 && c3_used1) {
    player_x_win = true;
  }
  if (a1_used1 && b2_used1 && c3_used1) {
    player_x_win = true;
  }
  if (a3_used1 && b2_used1 && c1_used1) {
    player_x_win = true;
  }
  //PLAYER O
  if (a1_used2 && a2_used2 && a3_used2) {
    player_o_win = true;
  }
  if (b1_used2 && b2_used2 && b3_used2) {
    player_o_win = true;
  }
  if (c1_used2 && c2_used2 && c3_used2) {
    player_o_win = true;
  }
  if (a1_used2 && b1_used2 && c1_used2) {
    player_o_win = true;
  }
  if (a2_used2 && b2_used2 && c2_used2) {
    player_o_win = true;
  }
  if (a3_used2 && b3_used2 && c3_used2) {
    player_o_win = true;
  }
  if (a1_used2 && b2_used2 && c3_used2) {
    player_o_win = true;
  }
  if (a3_used2 && b2_used2 && c1_used2) {
    player_o_win = true;
  }
  check_no_winner();
  if (player_x_win) {
    delay(500);
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 0));
    }
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1519 || i == 1470 || i == 1421 || i == 1372 || i == 1323 || i == 1274 || i == 1225 || i == 1176 || i == 1127 || i == 1078 || i == 1029 || i == 980 || i == 931 || i == 882 || i == 833 || i == 1223 || i == 1270 || i == 1317 || i == 1364 || i == 1411 || i == 1458 || i == 1505 || i == 1129 || i == 1082 || i == 1035 || i == 988 || i == 941 || i == 894 || i == 847) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
    led.show();
    player_x_win = false;
    ttt_start = 0;
    count_no_winner = 0;
    a1_used1 = false;
    a2_used1 = false;
    a3_used1 = false;
    b1_used1 = false;
    b2_used1 = false;
    b3_used1 = false;
    c1_used1 = false;
    c2_used1 = false;
    c3_used1 = false;
    a1_used2 = false;
    a2_used2 = false;
    a3_used2 = false;
    b1_used2 = false;
    b2_used2 = false;
    b3_used2 = false;
    c1_used2 = false;
    c2_used2 = false;
    c3_used2 = false;
    delay(2000);
  }
  if (player_o_win) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 0));
    }
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1410 || i == 1362 || i == 1314 || i == 1266 || i == 1218 || i == 1170 || i == 1122 || i == 1074 || i == 1026 || i == 978 || i == 930 || i == 1469 || i == 1468 || i == 1467 || i == 1466 || i == 1465 || i == 1464 || i == 1463 || i == 1462 || i == 1461 || i == 1460 || i == 1459 || i == 1422 || i == 1374 || i == 1326 || i == 1278 || i == 1230 || i == 1182 || i == 1134 || i == 1086 || i == 1038 || i == 990 || i == 942 || i == 893 || i == 892 || i == 891 || i == 890 || i == 889 || i == 888 || i == 887 || i == 886 || i == 885 || i == 884 || i == 883) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
    led.show();
    player_o_win = false;
    ttt_start = 0;
    count_no_winner = 0;
    a1_used1 = false;
    a2_used1 = false;
    a3_used1 = false;
    b1_used1 = false;
    b2_used1 = false;
    b3_used1 = false;
    c1_used1 = false;
    c2_used1 = false;
    c3_used1 = false;
    a1_used2 = false;
    a2_used2 = false;
    a3_used2 = false;
    b1_used2 = false;
    b2_used2 = false;
    b3_used2 = false;
    c1_used2 = false;
    c2_used2 = false;
    c3_used2 = false;
    delay(2000);
  }
  if (no_winner) {
    delay(500);
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 0));
    }
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1519 || i == 1470 || i == 1421 || i == 1372 || i == 1323 || i == 1274 || i == 1225 || i == 1176 || i == 1127 || i == 1078 || i == 1029 || i == 980 || i == 931 || i == 882 || i == 833 || i == 1223 || i == 1270 || i == 1317 || i == 1364 || i == 1411 || i == 1458 || i == 1505 || i == 1129 || i == 1082 || i == 1035 || i == 988 || i == 941 || i == 894 || i == 847) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
      if (i == 1410 || i == 1362 || i == 1314 || i == 1266 || i == 1218 || i == 1170 || i == 1122 || i == 1074 || i == 1026 || i == 978 || i == 930 || i == 1469 || i == 1468 || i == 1467 || i == 1466 || i == 1465 || i == 1464 || i == 1463 || i == 1462 || i == 1461 || i == 1460 || i == 1459 || i == 1422 || i == 1374 || i == 1326 || i == 1278 || i == 1230 || i == 1182 || i == 1134 || i == 1086 || i == 1038 || i == 990 || i == 942 || i == 893 || i == 892 || i == 891 || i == 890 || i == 889 || i == 888 || i == 887 || i == 886 || i == 885 || i == 884 || i == 883) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
    led.show();
    no_winner = false;
    count_no_winner = 0;
    ttt_start = 0;
    a1_used1 = false;
    a2_used1 = false;
    a3_used1 = false;
    b1_used1 = false;
    b2_used1 = false;
    b3_used1 = false;
    c1_used1 = false;
    c2_used1 = false;
    c3_used1 = false;
    a1_used2 = false;
    a2_used2 = false;
    a3_used2 = false;
    b1_used2 = false;
    b2_used2 = false;
    b3_used2 = false;
    c1_used2 = false;
    c2_used2 = false;
    c3_used2 = false;
    delay(2000);
  }
}
void select_field() {
  nunchuck1.readData();
  nunchuck2.readData();
  if (!beginner) {
    x_achse = nunchuck1.getJoyX();
    y_achse = nunchuck1.getJoyY();
  }
  if (beginner) {
    x_achse = nunchuck2.getJoyX();;
    y_achse = nunchuck2.getJoyY();
  }
  if (x_achse == 0) {
    x--;
    if (x <= 0) {
      x = 0;
    }
  }
  if (x_achse == 255) {
    x++;
    if (x >= 2) {
      x = 2;
    }
  }
  if (y_achse == 0) {
    y--;
    if (y <= 0) {
      y = 0;
    }
  }
  if (y_achse == 255) {
    y++;
    if (y >= 2) {
      y = 2;
    }
  }
  //B2//
  if (x == 1 && y == 1) {  //      #   #
    status = 1;            //   A1 #B1 # C1
  }                        // ###############
  //A2//                    //  A2 #B2 # C2
  if (x == 0 && y == 1) {  //      #   #
    status = 2;            // ###############
  }                        //   A3 #B3 # C3
  //A3//                    //      #   #
  if (x == 0 && y == 0) {
    status = 3;
  }
  //A1//
  if (x == 0 && y == 2) {
    status = 4;
  }
  //B3//
  if (x == 1 && y == 0) {
    status = 5;
  }
  //B1//
  if (x == 1 && y == 2) {
    status = 6;
  }
  //C2//
  if (x == 2 && y == 1) {
    status = 7;
  }
  //C3//
  if (x == 2 && y == 0) {
    status = 8;
  }
  //C1//
  if (x == 2 && y == 2) {
    status = 9;
  }
}
void draw_grid() {
  //zeichnet das Spielfeld für TIC TAC TOE sowie die belegten felder X und O
  for (int i = 0; i < MAXLED; i++) {
    led.setPixelColor(i, led.Color(0, 0, 0));
  }
  for (int i = 16; i < MAXLED; i += 48) {
    led.setPixelColor(i, led.Color(255, 255, 255));
  }
  for (int i = 32; i < MAXLED; i += 48) {
    led.setPixelColor(i, led.Color(255, 255, 255));
  }
  for (int i = 768; i < 815; i++) {
    led.setPixelColor(i, led.Color(255, 255, 255));
  }
  for (int i = 1536; i < 1583; i++) {
    led.setPixelColor(i, led.Color(255, 255, 255));
  }

  if (a1_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 2303 || i == 2254 || i == 2205 || i == 2156 || i == 2107 || i == 2058 || i == 2009 || i == 1960 || i == 1911 || i == 1862 || i == 1813 || i == 1764 || i == 1715 || i == 1666 || i == 1617 || i == 2007 || i == 2054 || i == 2101 || i == 2148 || i == 2195 || i == 2242 || i == 2289 || i == 1913 || i == 1866 || i == 1819 || i == 1772 || i == 1725 || i == 1678 || i == 1631) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (a2_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1535 || i == 1486 || i == 1437 || i == 1388 || i == 1339 || i == 1290 || i == 1241 || i == 1192 || i == 1143 || i == 1094 || i == 1045 || i == 996 || i == 947 || i == 898 || i == 849 || i == 1239 || i == 1286 || i == 1333 || i == 1380 || i == 1427 || i == 1474 || i == 1521 || i == 1145 || i == 1098 || i == 1051 || i == 1004 || i == 957 || i == 910 || i == 863) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (a3_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 767 || i == 718 || i == 669 || i == 620 || i == 571 || i == 522 || i == 473 || i == 424 || i == 375 || i == 326 || i == 277 || i == 228 || i == 179 || i == 130 || i == 81 || i == 471 || i == 518 || i == 565 || i == 612 || i == 659 || i == 706 || i == 753 || i == 377 || i == 330 || i == 283 || i == 236 || i == 189 || i == 142 || i == 95) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (b1_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1601 || i == 2287 || i == 2238 || i == 2189 || i == 2140 || i == 2091 || i == 2042 || i == 1993 || i == 1944 | i == 1895 || i == 1846 || i == 1797 || i == 1748 || i == 1699 || i == 1650 || i == 1991 || i == 2038 || i == 2085 || i == 2132 || i == 2179 || i == 2226 || i == 2273 || i == 1897 || i == 1850 || i == 1803 || i == 1756 || i == 1709 || i == 1662 || i == 1615) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (b2_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1519 || i == 1470 || i == 1421 || i == 1372 || i == 1323 || i == 1274 || i == 1225 || i == 1176 || i == 1127 || i == 1078 || i == 1029 || i == 980 || i == 931 || i == 882 || i == 833 || i == 1223 || i == 1270 || i == 1317 || i == 1364 || i == 1411 || i == 1458 || i == 1505 || i == 1129 || i == 1082 || i == 1035 || i == 988 || i == 941 || i == 894 || i == 847) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (b3_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 751 || i == 702 || i == 653 || i == 604 || i == 555 || i == 506 || i == 457 || i == 408 || i == 359 || i == 310 || i == 261 || i == 212 || i == 163 || i == 114 || i == 65 || i == 455 || i == 502 || i == 549 || i == 596 || i == 643 || i == 690 || i == 737 || i == 361 || i == 314 || i == 267 || i == 220 || i == 173 || i == 126 || i == 79) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (c1_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1585 || i == 2271 || i == 2222 || i == 2173 || i == 2124 || i == 2075 || i == 2026 || i == 1977 || i == 1928 || i == 1879 || i == 1830 || i == 1781 || i == 1732 || i == 1683 || i == 1634 || i == 1975 || i == 2022 || i == 2069 || i == 2116 || i == 2163 || i == 2210 || i == 2257 || i == 1881 || i == 1834 || i == 1787 || i == 1740 || i == 1693 || i == 1646 || i == 1599) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (c2_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1503 || i == 1454 || i == 1405 || i == 1356 || i == 1307 || i == 1258 || i == 1209 || i == 1160 || i == 1111 || i == 1062 || i == 1013 || i == 964 || i == 915 || i == 866 || i == 817 || i == 1207 || i == 1254 || i == 1301 || i == 1348 || i == 1395 || i == 1442 || i == 1489 || i == 1113 || i == 1066 || i == 1019 || i == 972 || i == 925 || i == 878 || i == 831) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (c3_used1) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 735 || i == 686 || i == 637 || i == 588 || i == 539 || i == 490 || i == 441 || i == 392 || i == 343 || i == 294 || i == 245 || i == 196 || i == 147 || i == 98 || i == 49 || i == 439 || i == 486 || i == 533 || i == 580 || i == 627 || i == 674 || i == 721 || i == 345 || i == 298 || i == 251 || i == 204 || i == 157 || i == 110 || i == 63) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
    }
  }
  if (a1_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 2194 || i == 2146 || i == 2098 || i == 2050 || i == 2002 || i == 1954 || i == 1906 || i == 1858 || i == 1810 || i == 1762 || i == 1714 || i == 2253 || i == 2252 || i == 2251 || i == 2250 || i == 2249 || i == 2248 || i == 2247 || i == 2246 || i == 2245 || i == 2244 || i == 2243 || i == 2206 || i == 2158 || i == 2110 || i == 2062 || i == 2014 || i == 1966 || i == 1918 || i == 1870 || i == 1822 || i == 1774 || i == 1726 || i == 1677 || i == 1676 || i == 1675 || i == 1674 || i == 1673 || i == 1672 || i == 1671 || i == 1670 || i == 1669 || i == 1668 || i == 1667) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (a2_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1426 || i == 1378 || i == 1330 || i == 1282 || i == 1234 || i == 1186 || i == 1138 || i == 1090 || i == 1042 || i == 994 || i == 946 || i == 1485 || i == 1484 || i == 1483 || i == 1482 || i == 1481 || i == 1480 || i == 1479 || i == 1478 || i == 1477 || i == 1476 || i == 1475 || i == 1438 || i == 1390 || i == 1342 || i == 1294 || i == 1246 || i == 1198 || i == 1150 || i == 1102 || i == 1054 || i == 1006 || i == 958 || i == 909 || i == 908 || i == 907 || i == 906 || i == 905 || i == 904 || i == 903 || i == 902 || i == 901 || i == 900 || i == 899) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (a3_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 658 || i == 610 || i == 562 || i == 514 || i == 466 || i == 418 || i == 370 || i == 322 || i == 274 || i == 226 || i == 178 || i == 717 || i == 716 || i == 715 || i == 714 || i == 713 || i == 712 || i == 711 || i == 710 || i == 709 || i == 708 || i == 707 || i == 670 || i == 622 || i == 574 || i == 526 || i == 478 || i == 430 || i == 382 || i == 334 || i == 286 || i == 238 || i == 190 || i == 141 || i == 140 || i == 139 || i == 138 || i == 137 || i == 136 || i == 135 || i == 134 || i == 133 || i == 132 || i == 131) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (b1_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 2178 || i == 2130 || i == 2082 || i == 2034 || i == 1986 || i == 1938 || i == 1890 || i == 1842 || i == 1794 || i == 1746 || i == 1698 || i == 2237 || i == 2236 || i == 2235 || i == 2234 || i == 2233 || i == 2232 || i == 2231 || i == 2230 || i == 2229 || i == 2228 || i == 2227 || i == 2190 || i == 2142 || i == 2094 || i == 2046 || i == 1998 || i == 1950 || i == 1902 || i == 1854 || i == 1806 || i == 1758 || i == 1710 || i == 1661 || i == 1660 || i == 1659 || i == 1658 || i == 1657 || i == 1656 || i == 1655 || i == 1654 || i == 1653 || i == 1652 || i == 1651) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (b2_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1410 || i == 1362 || i == 1314 || i == 1266 || i == 1218 || i == 1170 || i == 1122 || i == 1074 || i == 1026 || i == 978 || i == 930 || i == 1469 || i == 1468 || i == 1467 || i == 1466 || i == 1465 || i == 1464 || i == 1463 || i == 1462 || i == 1461 || i == 1460 || i == 1459 || i == 1422 || i == 1374 || i == 1326 || i == 1278 || i == 1230 || i == 1182 || i == 1134 || i == 1086 || i == 1038 || i == 990 || i == 942 || i == 893 || i == 892 || i == 891 || i == 890 || i == 889 || i == 888 || i == 887 || i == 886 || i == 885 || i == 884 || i == 883) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (b3_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 642 || i == 594 || i == 546 || i == 498 || i == 450 || i == 402 || i == 354 || i == 306 || i == 258 || i == 210 || i == 162 || i == 701 || i == 700 || i == 699 || i == 698 || i == 697 || i == 696 || i == 695 || i == 694 || i == 693 || i == 692 || i == 691 || i == 654 || i == 606 || i == 558 || i == 510 || i == 462 || i == 414 || i == 366 || i == 318 || i == 270 || i == 222 || i == 174 || i == 125 || i == 124 || i == 123 || i == 122 || i == 121 || i == 120 || i == 119 || i == 118 || i == 117 || i == 116 || i == 115) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (c1_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1682 || i == 2221 || i == 2220 || i == 2162 || i == 2114 || i == 2066 || i == 2018 || i == 1970 || i == 1922 || i == 1874 || i == 1826 || i == 1778 || i == 1730 || i == 2219 || i == 2218 || i == 2217 || i == 2216 || i == 2215 || i == 2214 || i == 2213 || i == 2212 || i == 2211 || i == 2174 || i == 2126 || i == 2078 || i == 2030 || i == 1982 || i == 1934 || i == 1886 || i == 1838 || i == 1790 || i == 1742 || i == 1694 || i == 1645 || i == 1644 || i == 1643 || i == 1642 || i == 1641 || i == 1640 || i == 1639 || i == 1638 || i == 1637 || i == 1636 || i == 1635) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (c2_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1394 || i == 1346 || i == 1298 || i == 1250 || i == 1202 || i == 1154 || i == 1106 || i == 1058 || i == 1010 || i == 962 || i == 914 || i == 1453 || i == 1452 || i == 1451 || i == 1450 || i == 1449 || i == 1448 || i == 1447 || i == 1446 || i == 1445 || i == 1444 || i == 1443 || i == 1406 || i == 1358 || i == 1310 || i == 1262 || i == 1214 || i == 1166 || i == 1118 || i == 1070 || i == 1022 || i == 974 || i == 926 || i == 877 || i == 876 || i == 875 || i == 874 || i == 873 || i == 872 || i == 871 || i == 870 || i == 869 || i == 868 || i == 867) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  if (c3_used2) {
    for (int i = 0; i < MAXLED; i++) {
      if (i == 626 || i == 578 || i == 530 || i == 482 || i == 434 || i == 386 || i == 338 || i == 290 || i == 242 || i == 194 || i == 146 || i == 685 || i == 684 || i == 683 || i == 682 || i == 681 || i == 680 || i == 679 || i == 678 || i == 677 || i == 676 || i == 675 || i == 638 || i == 590 || i == 542 || i == 494 || i == 446 || i == 398 || i == 350 || i == 302 || i == 254 || i == 206 || i == 158 || i == 109 || i == 108 || i == 107 || i == 106 || i == 105 || i == 104 || i == 103 || i == 102 || i == 101 || i == 100 || i == 99) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
    }
  }
  led.show();
}
//

//COIN COLLECT FUNKTIONEN//
void coin() {
  if (countcoin_ran == dotnew) {  //add coin an einer zufälligen Position
    ran = (1 + rand() % 2304);
    led.setPixelColor(ran, led.Color(255, 255, 0));
    countcoin_ran = 0;
  }
  if (countcoin_ran2 == dotnew) {  //add coin an einer zufälligen Position
    ran2 = (1 + rand() % 2304);
    led.setPixelColor(ran2, led.Color(255, 255, 0));
    countcoin_ran2 = 0;
  }
  //player 1 check coin
  if (101 + n1 == ran || 100 + n1 == ran || 149 + n1 == ran || 148 + n1 == ran) {
    score1++;
    countcoin_ran = dotnew;
  } else if (101 + n1 == ran2 || 100 + n1 == ran2 || 149 + n1 == ran2 || 148 + n1 == ran2) {
    score1++;
    countcoin_ran2 = dotnew;
  }
  //player 2 check coin
  if (139 + n2 == ran || 138 + n2 == ran || 187 + n2 == ran || 186 + n2 == ran) {
    score2++;
    countcoin_ran = dotnew;
  } else if (139 + n2 == ran2 || 138 + n2 == ran2 || 187 + n2 == ran2 || 186 + n2 == ran2) {
    score2++;
    countcoin_ran2 = dotnew;
  }
  //player 3 check coin
  if (156 + n3 == ran || 155 + n3 == ran || 108 + n3 == ran || 107 + n3 == ran) {
    score3++;
    countcoin_ran = dotnew;
  } else if (156 + n3 == ran2 || 155 + n3 == ran2 || 108 + n3 == ran2 || 107 + n3 == ran2) {
    score3++;
    countcoin_ran2 = dotnew;
  }
  //player 4 check coin
  if (180 + n4 == ran || 179 + n4 == ran || 132 + n4 == ran || 131 + n4 == ran) {
    score4++;
    countcoin_ran = dotnew;
  } else if (180 + n4 == ran2 || 179 + n4 == ran2 || 132 + n4 == ran2 || 131 + n4 == ran2) {
    score4++;
    countcoin_ran2 = dotnew;
  }
  led_update();
}
void led_update() {
  for (int i = 0; i < MAXLED; i++) {
    led.setPixelColor(i, led.Color(0, 0, 0));
  }
  led.setPixelColor(ran, led.Color(255, 255, 0));
  led.setPixelColor(ran2, led.Color(255, 255, 0));
  //draw player 1
  for (int i = 100; i < 151; i++) {
    if (i == 100 || i == 101 || i == 149 || i == 148) {
      led.setPixelColor(i + n1, led.Color(255, 0, 0));
    }
  }
  //draw player 2
  for (int i = 137; i < 189; i++) {
    if (i == 138 || i == 139 || i == 187 || i == 186) {
      led.setPixelColor(i + n2, led.Color(0, 255, 0));
    }
  }
  //draw player 3
  for (int i = 106; i < 158; i++) {
    if (i == 156 || i == 155 || i == 107 || i == 108) {
      led.setPixelColor(i + n3, led.Color(0, 0, 255));
    }
  }
  //draw player 4
  for (int i = 130; i < 182; i++) {
    if (i == 131 || i == 132 || i == 180 || i == 179) {
      led.setPixelColor(i + n4, led.Color(255, 255, 255));
    }
  }
  led.show();
}
void check_pos() {
  nunchuck1.readData();
  nunchuck2.readData();
  nunchuck3.readData();
  nunchuck4.readData();
  //PLAYER 1 Position

  if (nunchuck1.getJoyX() > 180)  //player 1 right
  {
    n1 = n1 - 1;
    standby_Timer = 0;
  }
  if (nunchuck1.getJoyX() < 80)  //player 1 left
  {
    n1 = n1 + 1;
  }
  if (nunchuck1.getJoyY() > 180)  //player 1 up
  {
    n1 = n1 + 48;
    if (n1 > MAXLED) {
      n1 -= MAXLED;
    }
  }
  if (nunchuck1.getJoyY() < 80)  //player 1 down
  {
    n1 = n1 - 48;
    if (n1 < -96) {
      n1 += MAXLED;
    }
  }
  //PLAYER 2 Position

  if (nunchuck2.getJoyX() > 180)  //player 2 right
  {
    n2 = n2 - 1;
    standby_Timer = 0;
  }
  if (nunchuck2.getJoyX() < 80)  //player 2 left
  {
    n2 = n2 + 1;
  }
  if (nunchuck2.getJoyY() > 180)  //player 2 up
  {
    n2 = n2 + 48;
    if (n2 > MAXLED) {
      n2 -= MAXLED;
    }
  }
  if (nunchuck2.getJoyY() < 80)  //player 2 down
  {
    n2 = n2 - 48;
    if (n2 < -96) {
      n2 += MAXLED;
    }
  }
  //PLAYER 3 Position

  if (nunchuck3.getJoyX() > 180)  //player 3 right
  {
    n3 = n3 - 1;
    standby_Timer = 0;
  }
  if (nunchuck3.getJoyX() < 80)  //player 3 left
  {
    n3 = n3 + 1;
  }
  if (nunchuck3.getJoyY() > 180)  //player 3 up
  {
    n3 = n3 + 48;
    if (n3 > MAXLED) {
      n3 -= MAXLED;
    }
  }
  if (nunchuck3.getJoyY() < 80)  //player 3 down
  {
    n3 = n3 - 48;
    if (n3 < -96) {
      n3 += MAXLED;
    }
  }
  //PLAYER 4 Position

  if (nunchuck4.getJoyX() > 180)  //player 4 right
  {
    n4 = n4 - 1;
    standby_Timer = 0;
  }
  if (nunchuck4.getJoyX() < 80)  //player 4 left
  {
    n4 = n4 + 1;
  }
  if (nunchuck2.getJoyY() > 180)  //player 4 up
  {
    n4 = n4 + 48;
    if (n4 > MAXLED) {
      n4 -= MAXLED;
    }
  }
  if (nunchuck2.getJoyY() < 80)  //player 4 down
  {
    n4 = n4 - 48;
    if (n4 < -96) {
      n4 += MAXLED;
    }
  }
}
void check_win_coin_collect() {
  //player1 win screen
  if (score1 >= 7) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(255, 0, 0));
    }
    led.show();
    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    score1 = 0;
    score2 = 0;
    score3 = 0;
    score4 = 0;
    delay(1000);
  }
  //player2 win screen
  if (score2 >= 7) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 255, 0));
    }
    led.show();
    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    score1 = 0;
    score2 = 0;
    score3 = 0;
    score4 = 0;
    delay(1000);
  }
  //player3 win screen
  if (score3 >= 7) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 255));
    }
    led.show();
    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    score1 = 0;
    score2 = 0;
    score3 = 0;
    score4 = 0;
    delay(1000);
  }
  //player4 win screen
  if (score4 >= 7) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(150, 150, 150));
    }
    led.show();
    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    score1 = 0;
    score2 = 0;
    score3 = 0;
    score4 = 0;
    delay(1000);
  }
}


void game_ONE_LED_RACE() {
  if (select == 1) {
    //Start Sequenz
    if (run == 0) {
      for (int i = 0; i < MAXLED; i++) {
        led.setPixelColor(i, led.Color(0, 0, 0));
      }
      for (int i = 0; i < MAXLED; i++) {
        if (i == 1851 || i == 1850 || i == 1849 || i == 1848 || i == 1847 || i == 1846 || i == 1803 || i == 1802 || i == 1801 || i == 1800 || i == 1799 || i == 1798 || i == 1797 || i == 1749 || i == 1748 || i == 1747 || i == 1700 || i == 1699 || i == 1652 || i == 1651 || i == 1604 || i == 1603 || i == 1556 || i == 1555 || i == 1508 || i == 1507 || i == 1460 || i == 1459 || i == 1412 || i == 1411 || i == 1364 || i == 1363 || i == 1316 || i == 1315 || i == 1268 || i == 1267 || i == 1221 || i == 1220 || i == 1219 || i == 1173 || i == 1131 || i == 1130 || i == 1129 || i == 1128 || i == 1127 || i == 1126 || i == 1083 || i == 1082 || i == 1081 || i == 1080 || i == 1079 || i == 1078 || i == 1029 || i == 981 || i == 980 || i == 979 || i == 932 || i == 931 || i == 884 || i == 883 || i == 836 || i == 835 || i == 788 || i == 787 || i == 740 || i == 739 || i == 692 || i == 691 || i == 644 || i == 643 || i == 596 || i == 595 || i == 548 || i == 547 || i == 500 || i == 499 || i == 453 || i == 452 || i == 451 || i == 411 || i == 410 || i == 409 || i == 408 || i == 407 || i == 406 || i == 405 || i == 363 || i == 362 || i == 361 || i == 360 || i == 359 || i == 358) {
          led.setPixelColor(i, led.Color(255, 0, 0));
        }
      }
      led.show();
      delay(1000);
      for (int i = 0; i < MAXLED; i++) {
        led.setPixelColor(i, led.Color(0, 0, 0));
      }
      for (int i = 0; i < MAXLED; i++) {
        if (i == 1660 || i == 1659 || i == 1708 || i == 1707 || i == 1755 || i == 1754 || i == 1802 || i == 1801 || i == 1849 || i == 1848 || i == 1847 || i == 1846 || i == 1845 || i == 1844 || i == 1843 || i == 1896 || i == 1895 || i == 1894 || i == 1893 || i == 1796 || i == 1795 || i == 1794 || i == 1746 || i == 1745 || i == 1697 || i == 1696 || i == 1649 || i == 1648 || i == 1601 || i == 1600 || i == 1553 || i == 1552 || i == 1505 || i == 1504 || i == 1457 || i == 1456 || i == 1409 || i == 1408 || i == 1361 || i == 1360 || i == 1313 || i == 1312 || i == 1266 || i == 1265 || i == 1218 || i == 1217 || i == 1171 || i == 1170 || i == 1123 || i == 1122 || i == 1076 || i == 1075 || i == 1028 || i == 1027 || i == 981 || i == 980 || i == 933 || i == 932 || i == 886 || i == 885 || i == 838 || i == 837 || i == 791 || i == 790 || i == 743 || i == 742 || i == 696 || i == 695 || i == 648 || i == 647 || i == 601 || i == 600 || i == 553 || i == 552 || i == 506 || i == 505 || i == 459 || i == 458 || i == 457 || i == 411 || i == 410 || i == 409 || i == 408 || i == 407 || i == 406 || i == 405 || i == 404 || i == 403 || i == 402 || i == 401 || i == 400 || i == 399 || i == 363 || i == 362 || i == 361 || i == 360 || i == 359 || i == 358 || i == 357 || i == 356 || i == 355 || i == 354 || i == 353 || i == 352 || i == 351) {
          led.setPixelColor(i, led.Color(255, 255, 0));
        }
      }
      led.show();
      delay(1000);
      for (int i = 0; i < MAXLED; i++) {
        led.setPixelColor(i, led.Color(0, 0, 0));
      }
      for (int i = 0; i < MAXLED; i++) {
        if (i == 1468 || i == 1516 || i == 1515 || i == 1563 || i == 1562 || i == 1610 || i == 1609 || i == 1657 || i == 1656 || i == 1704 || i == 1703 || i == 1751 || i == 1750 || i == 1798 || i == 1797 || i == 1845 || i == 1844 || i == 1843 || i == 1796 || i == 1795 || i == 1748 || i == 1747 || i == 1700 || i == 1699 || i == 1652 || i == 1651 || i == 1604 || i == 1603 || i == 1556 || i == 1555 || i == 1508 || i == 1507 || i == 1460 || i == 1459 || i == 1412 || i == 1411 || i == 1364 || i == 1363 || i == 1316 || i == 1315 || i == 1268 || i == 1267 || i == 1220 || i == 1219 || i == 1172 || i == 1171 || i == 1124 || i == 1123 || i == 1076 || i == 1075 || i == 1028 || i == 1027 || i == 980 || i == 979 || i == 932 || i == 931 || i == 884 || i == 883 || i == 836 || i == 835 || i == 788 || i == 787 || i == 740 || i == 739 || i == 692 || i == 691 || i == 644 || i == 643 || i == 596 || i == 595 || i == 548 || i == 547 || i == 500 || i == 499 || i == 452 || i == 451 || i == 404 || i == 403 || i == 356 || i == 355) {
          led.setPixelColor(i, led.Color(0, 255, 0));
        }
      }
      led.show();
      delay(1000);
      for (int i = 0; i < MAXLED; i++) {
        led.setPixelColor(i, led.Color(0, 0, 0));
      }
      for (int i = 0; i < MAXLED; i++) {
        if (i == 1591 || i == 1186 || i == 1185 || i == 1184 || i == 1183 || i == 1182 || i == 1181 || i == 1180 || i == 1179 || i == 1138 || i == 1137 || i == 1136 || i == 1135 || i == 1134 || i == 1133 || i == 1132 || i == 1131 || i == 1130 || i == 1082 || i == 1034 || i == 1033 || i == 985 || i == 937 || i == 889 || i == 842 || i == 841 || i == 794 || i == 758 || i == 757 || i == 756 || i == 755 || i == 754 || i == 753 || i == 752 || i == 751 || i == 750 || i == 749 || i == 748 || i == 747 || i == 746 || i == 709 || i == 708 || i == 707 || i == 706 || i == 705 || i == 704 || i == 703 || i == 702 || i == 701 || i == 700 || i == 699 || i == 807 || i == 806 || i == 855 || i == 904 || i == 903 || i == 953 || i == 952 || i == 1001 || i == 1000 || i == 1049 || i == 1048 || i == 1097 || i == 1096 || i == 1145 || i == 1144 || i == 1193 || i == 1192 || i == 1241 || i == 1240 || i == 1289 || i == 1288 || i == 1337 || i == 1336 || i == 1385 || i == 1384 || i == 1432 || i == 1431 || i == 1479 || i == 1527 || i == 1526 || i == 1574 || i == 1573 || i == 1621 || i == 1669 || i == 1668 || i == 1716 || i == 1715 || i == 1714 || i == 1713 || i == 1712 || i == 1711 || i == 1710 || i == 1709 || i == 1708 || i == 1707 || i == 1706 || i == 1763 || i == 1762 || i == 1761 || i == 1760 || i == 1759 || i == 1758 || i == 1757 || i == 1756 || i == 1755 || i == 1658 || i == 1610 || i == 1609 || i == 1561 || i == 1749 || i == 1748 || i == 1747 || i == 1746 || i == 1745 || i == 1744 || i == 1743 || i == 1742 || i == 1741 || i == 1740 || i == 1739 || i == 1738 || i == 1737 || i == 1736 || i == 1702 || i == 1701 || i == 1700 || i == 1699 || i == 1698 || i == 1697 || i == 1696 || i == 1695 || i == 1694 || i == 1693 || i == 1692 || i == 1691 || i == 1690 || i == 1689 || i == 1688 || i == 1687 || i == 1654 || i == 1639 || i == 1607 || i == 1606 || i == 1590 || i == 1559 || i == 1558 || i == 1543 || i == 1542 || i == 1511 || i == 1510 || i == 1495 || i == 1494 || i == 1463 || i == 1462 || i == 1447 || i == 1446 || i == 1415 || i == 1414 || i == 1367 || i == 1366 || i == 1319 || i == 1318 || i == 1271 || i == 1270 || i == 1223 || i == 1222 || i == 1175 || i == 1174 || i == 1127 || i == 1126 || i == 1079 || i == 1078 || i == 1031 || i == 1030 || i == 983 || i == 982 || i == 935 || i == 934 || i == 887 || i == 886 || i == 839 || i == 838 || i == 790 || i == 1399 || i == 1398 || i == 1351 || i == 1350 || i == 1303 || i == 1302 || i == 1255 || i == 1254 || i == 1207 || i == 1206 || i == 1159 || i == 1158 || i == 1111 || i == 1110 || i == 1063 || i == 1062 || i == 1015 || i == 1014 || i == 967 || i == 966 || i == 919 || i == 918 || i == 871 || i == 870 || i == 823 || i == 822 || i == 775 || i == 742 || i == 741 || i == 740 || i == 739 || i == 738 || i == 737 || i == 736 || i == 735 || i == 734 || i == 733 || i == 732 || i == 731 || i == 730 || i == 729 || i == 728 || i == 727 || i == 693 || i == 692 || i == 691 || i == 690 || i == 689 || i == 688 || i == 687 || i == 686 || i == 685 || i == 684 || i == 683 || i == 682 || i == 681 || i == 680) {
          led.setPixelColor(i, led.Color(255, 255, 255));
        }
      }
      led.show();
      delay(1000);
      for (int i = 0; i < MAXLED; i++) {
        led.setPixelColor(i, led.Color(0, 0, 0));
      }
      led.show();
      timestamp = 0;

      run = 1;
    }
    //
    if (run == 1) {
      easter_counter = 0;
      //Festlegen der Gesch´windikeit der Spieler
      //Überprüft ob der Knopf gedrückt bleibt oder Wiederholt gedrückt wird
      //kf bremst den Spieler langsam ab
      nunchuck1.readData();
      nunchuck2.readData();
      nunchuck3.readData();
      nunchuck4.readData();
      for (int i = 0; i < MAXLED; i++) {
        led.setPixelColor(i, led.Color(0, 0, 0));
      }
      if ((flag_sw1 == 1) && nunchuck1.getButtonC() == 1) {
        standby_Timer = 0;
        flag_sw1 = 0;
        speed1 += ACEL;
      }
      if ((flag_sw1 == 0) && nunchuck1.getButtonC() == 0) {
        flag_sw1 = 1;
      }
      speed1 -= speed1 * kf;

      if ((flag_sw2 == 1) && nunchuck2.getButtonC() == 1) {
        standby_Timer = 0;
        flag_sw2 = 0;
        speed2 += ACEL;
      }
      if ((flag_sw2 == 0) && nunchuck2.getButtonC() == 0) {
        flag_sw2 = 1;
      }
      speed2 -= speed2 * kf;

      if ((flag_sw3 == 1) && nunchuck3.getButtonC() == 1) {
        standby_Timer = 0;
        flag_sw3 = 0;
        speed3 += ACEL;
      }
      if ((flag_sw3 == 0) && nunchuck3.getButtonC() == 0) {
        flag_sw3 = 1;
      }
      speed3 -= speed3 * kf;

      if ((flag_sw4 == 1) && nunchuck4.getButtonC() == 1) {
        standby_Timer = 0;
        flag_sw4 = 0;
        speed4 += ACEL;
      }
      if ((flag_sw4 == 0) && nunchuck4.getButtonC() == 0) {
        flag_sw4 = 1;
      }
      speed4 -= speed4 * kf;
      //legt die Distanz fest die die Spieler zurückgelegt haben
      //dist1-4 wird zum Anzeigen der aktuellen Position jedes Spielers benutz
      dist1 += speed1;
      dist2 += speed2;
      dist3 += speed3;
      dist4 += speed4;

      if (dist1 > dist2 && dist1 > dist3 && dist1 > dist4) {
        leader = 1;
      }
      if (dist2 > dist1 && dist2 > dist3 && dist2 > dist4) {
        leader = 2;
      }
      if (dist3 > dist1 && dist3 > dist2 && dist3 > dist4) {
        leader = 3;
      }
      if (dist4 > dist1 && dist4 > dist2 && dist4 > dist3) {
        leader = 4;
      }

      if (dist1 > MAXLED * loop1) {
        loop1++;
        tone(PIN_AUDIO, 600);
        TBEEP = 2;
      }
      if (dist2 > MAXLED * loop2) {
        loop2++;
        tone(PIN_AUDIO, 700);
        TBEEP = 2;
      }
      if (dist3 > MAXLED * loop3) {
        loop3++;
        tone(PIN_AUDIO, 800);
        TBEEP = 2;
      }
      if (dist4 > MAXLED * loop4) {
        loop4++;
        tone(PIN_AUDIO, 900);
        TBEEP = 2;
      }
      //Rundenzähler für jeden Spieler einzeln
      if (loop1 > loop_max) {
        for (int i = 0; i < MAXLED; i++) {
          led.setPixelColor(i, led.Color(255, 0, 0));
        }
        led.show();
        loop1 = 5;
        loop2 = 5;
        loop3 = 5;
        loop4 = 5;
        dist1 = 9216;
        dist2 = 9216;
        dist3 = 9216;
        dist4 = 9216;
        speed1 = 0;
        speed2 = 0;
        speed3 = 0;
        speed4 = 0;
        run = 0;
        timestamp = 0;
        delay(race_win_delay);
      }

      if (loop2 > loop_max) {
        for (int i = 0; i < MAXLED; i++) {
          led.setPixelColor(i, led.Color(0, 255, 0));
        }
        led.show();
        loop1 = 5;
        loop2 = 5;
        loop3 = 5;
        loop4 = 5;
        dist1 = 9216;
        dist2 = 9216;
        dist3 = 9216;
        dist4 = 9216;
        speed1 = 0;
        speed2 = 0;
        speed3 = 0;
        speed4 = 0;
        run = 0;
        timestamp = 0;
        delay(race_win_delay);
      }

      if (loop3 > loop_max) {
        for (int i = 0; i < MAXLED; i++) {
          led.setPixelColor(i, led.Color(0, 0, 255));
        }
        led.show();
        loop1 = 5;
        loop2 = 5;
        loop3 = 5;
        loop4 = 5;
        dist1 = 9216;
        dist2 = 9216;
        dist3 = 9216;
        dist4 = 9216;
        speed1 = 0;
        speed2 = 0;
        speed3 = 0;
        speed4 = 0;
        run = 0;
        timestamp = 0;
        delay(race_win_delay);
      }

      if (loop4 > loop_max) {
        for (int i = 0; i < MAXLED; i++) {
          led.setPixelColor(i, led.Color(255, 255, 255));
        }
        led.show();
        loop1 = 5;
        loop2 = 5;
        loop3 = 5;
        loop4 = 5;
        dist1 = 9216;
        dist2 = 9216;
        dist3 = 9216;
        dist4 = 9216;
        speed1 = 0;
        speed2 = 0;
        speed3 = 0;
        speed4 = 0;
        run = 0;
        timestamp = 0;
        delay(race_win_delay);
      }
      //Legt die reihenfolge und die geschwindigkeit fest in der die Spieler angezeigt werden wenn diese übereinander sind
      if ((millis() & 512) == (512 * draworder)) {
        if (draworder == 0) {
          draworder = 1;
        } else {
          draworder = 0;
        }
      }

      if (draworder == 0) {
        draw_car1();
        draw_car2();
        draw_car3();
        draw_car4();
      } else {
        draw_car4();
        draw_car3();
        draw_car2();
        draw_car1();
      }
      led.show();
      delay(tdelay);

      if (TBEEP > 0) {
        TBEEP -= 1;
        if (TBEEP == 0) {
          noTone(PIN_AUDIO);
        }
      }
    }
  }
}
//

void game_TWO_TIC_TAC_TOE() {
  if (select == 2) {
    if (ttt_start == 0) {
      draw_grid();
      select_beginner = random(10);
      if (select_beginner <= 5) {
        beginner = false;
      }
      if (select_beginner >= 6) {
        beginner = true;
      }
      ttt_start = 1;
    }
    if (ttt_start == 1) {
      draw_grid();
      select_field();
      easter_counter = 0;
      if (!beginner) {
        nunchuck1.readData();
        status_pressed = nunchuck1.getButtonC();
        check_win_tic_tac_toe();
        //Überprüft ob die gewählte Position frei ist oder belegt ist
        //Nach jeder positions eingabe wird überprüft ob diese zum Gewinnen des Spiels geführt hat oder zu einem Unentschieden
        if (status == 1) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1519 || i == 1470 || i == 1421 || i == 1372 || i == 1323 || i == 1274 || i == 1225 || i == 1176 || i == 1127 || i == 1078 || i == 1029 || i == 980 || i == 931 || i == 882 || i == 833 || i == 1223 || i == 1270 || i == 1317 || i == 1364 || i == 1411 || i == 1458 || i == 1505 || i == 1129 || i == 1082 || i == 1035 || i == 988 || i == 941 || i == 894 || i == 847) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !b2_used1 && !b2_used2) {
            b2_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 2) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1535 || i == 1486 || i == 1437 || i == 1388 || i == 1339 || i == 1290 || i == 1241 || i == 1192 || i == 1143 || i == 1094 || i == 1045 || i == 996 || i == 947 || i == 898 || i == 849 || i == 1239 || i == 1286 || i == 1333 || i == 1380 || i == 1427 || i == 1474 || i == 1521 || i == 1145 || i == 1098 || i == 1051 || i == 1004 || i == 957 || i == 910 || i == 863) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !a2_used1 && !a2_used2) {
            a2_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 3) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 767 || i == 718 || i == 669 || i == 620 || i == 571 || i == 522 || i == 473 || i == 424 || i == 375 || i == 326 || i == 277 || i == 228 || i == 179 || i == 130 || i == 81 || i == 471 || i == 518 || i == 565 || i == 612 || i == 659 || i == 706 || i == 753 || i == 377 || i == 330 || i == 283 || i == 236 || i == 189 || i == 142 || i == 95) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !a3_used1 && !a3_used2) {
            a3_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 4) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 2303 || i == 2254 || i == 2205 || i == 2156 || i == 2107 || i == 2058 || i == 2009 || i == 1960 || i == 1911 || i == 1862 || i == 1813 || i == 1764 || i == 1715 || i == 1666 || i == 1617 || i == 2007 || i == 2054 || i == 2101 || i == 2148 || i == 2195 || i == 2242 || i == 2289 || i == 1913 || i == 1866 || i == 1819 || i == 1772 || i == 1725 || i == 1678 || i == 1631) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !a1_used1 && !a1_used2) {
            a1_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 5) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 751 || i == 702 || i == 653 || i == 604 || i == 555 || i == 506 || i == 457 || i == 408 || i == 359 || i == 310 || i == 261 || i == 212 || i == 163 || i == 114 || i == 65 || i == 455 || i == 502 || i == 549 || i == 596 || i == 643 || i == 690 || i == 737 || i == 361 || i == 314 || i == 267 || i == 220 || i == 173 || i == 126 || i == 79) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !b3_used1 && !b3_used2) {
            b3_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 6) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 2287 || i == 2238 || i == 2189 || i == 2140 || i == 2091 || i == 2042 || i == 1993 || i == 1944 | i == 1895 || i == 1846 || i == 1797 || i == 1748 || i == 1699 || i == 1650 || i == 1991 || i == 2038 || i == 2085 || i == 2132 || i == 2179 || i == 2226 || i == 2273 || i == 1897 || i == 1850 || i == 1803 || i == 1756 || i == 1709 || i == 1662 || i == 1615) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !b1_used1 && !b1_used2) {
            b1_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 7) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1503 || i == 1454 || i == 1405 || i == 1356 || i == 1307 || i == 1258 || i == 1209 || i == 1160 || i == 1111 || i == 1062 || i == 1013 || i == 964 || i == 915 || i == 866 || i == 817 || i == 1207 || i == 1254 || i == 1301 || i == 1348 || i == 1395 || i == 1442 || i == 1489 || i == 1113 || i == 1066 || i == 1019 || i == 972 || i == 925 || i == 878 || i == 831) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !c2_used1 && !c2_used2) {
            c2_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 8) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 735 || i == 686 || i == 637 || i == 588 || i == 539 || i == 490 || i == 441 || i == 392 || i == 343 || i == 294 || i == 245 || i == 196 || i == 147 || i == 98 || i == 49 || i == 439 || i == 486 || i == 533 || i == 580 || i == 627 || i == 674 || i == 721 || i == 345 || i == 298 || i == 251 || i == 204 || i == 157 || i == 110 || i == 63) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !c3_used1 && !c3_used2) {
            c3_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
        if (status == 9) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1585 || i == 2271 || i == 2222 || i == 2173 || i == 2124 || i == 2075 || i == 2026 || i == 1977 || i == 1928 || i == 1879 || i == 1830 || i == 1781 || i == 1732 || i == 1683 || i == 1634 || i == 1975 || i == 2022 || i == 2069 || i == 2116 || i == 2163 || i == 2210 || i == 2257 || i == 1881 || i == 1834 || i == 1787 || i == 1740 || i == 1693 || i == 1646 || i == 1599) {
              led.setPixelColor(i, led.Color(255, 0, 0));
            }
          }
          led.show();
          if (status_pressed == 1 && !c1_used1 && !c1_used2) {
            c1_used1 = true;
            beginner = true;
            count_no_winner += 1;
          }
        }
      }
      if (beginner) {
        nunchuck2.readData();
        status_pressed1 = nunchuck2.getButtonC();
        check_win_tic_tac_toe();
        if (status == 1) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1410 || i == 1362 || i == 1314 || i == 1266 || i == 1218 || i == 1170 || i == 1122 || i == 1074 || i == 1026 || i == 978 || i == 930 || i == 1469 || i == 1468 || i == 1467 || i == 1466 || i == 1465 || i == 1464 || i == 1463 || i == 1462 || i == 1461 || i == 1460 || i == 1459 || i == 1422 || i == 1374 || i == 1326 || i == 1278 || i == 1230 || i == 1182 || i == 1134 || i == 1086 || i == 1038 || i == 990 || i == 942 || i == 893 || i == 892 || i == 891 || i == 890 || i == 889 || i == 888 || i == 887 || i == 886 || i == 885 || i == 884 || i == 883) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !b2_used1 && !b2_used2) {
            b2_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 2) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1426 || i == 1378 || i == 1330 || i == 1282 || i == 1234 || i == 1186 || i == 1138 || i == 1090 || i == 1042 || i == 994 || i == 946 || i == 1485 || i == 1484 || i == 1483 || i == 1482 || i == 1481 || i == 1480 || i == 1479 || i == 1478 || i == 1477 || i == 1476 || i == 1475 || i == 1438 || i == 1390 || i == 1342 || i == 1294 || i == 1246 || i == 1198 || i == 1150 || i == 1102 || i == 1054 || i == 1006 || i == 958 || i == 909 || i == 908 || i == 907 || i == 906 || i == 905 || i == 904 || i == 903 || i == 902 || i == 901 || i == 900 || i == 899) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !a2_used1 && !a2_used2) {
            a2_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 3) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 658 || i == 610 || i == 562 || i == 514 || i == 466 || i == 418 || i == 370 || i == 322 || i == 274 || i == 226 || i == 178 || i == 717 || i == 716 || i == 715 || i == 714 || i == 713 || i == 712 || i == 711 || i == 710 || i == 709 || i == 708 || i == 707 || i == 670 || i == 622 || i == 574 || i == 526 || i == 478 || i == 430 || i == 382 || i == 334 || i == 286 || i == 238 || i == 190 || i == 141 || i == 140 || i == 139 || i == 138 || i == 137 || i == 136 || i == 135 || i == 134 || i == 133 || i == 132 || i == 131) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !a3_used1 && !a3_used2) {
            a3_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 4) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 2194 || i == 2146 || i == 2098 || i == 2050 || i == 2002 || i == 1954 || i == 1906 || i == 1858 || i == 1810 || i == 1762 || i == 1714 || i == 2253 || i == 2252 || i == 2251 || i == 2250 || i == 2249 || i == 2248 || i == 2247 || i == 2246 || i == 2245 || i == 2244 || i == 2243 || i == 2206 || i == 2158 || i == 2110 || i == 2062 || i == 2014 || i == 1966 || i == 1918 || i == 1870 || i == 1822 || i == 1774 || i == 1726 || i == 1677 || i == 1676 || i == 1675 || i == 1674 || i == 1673 || i == 1672 || i == 1671 || i == 1670 || i == 1669 || i == 1668 || i == 1667) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !a1_used1 && !a1_used2) {
            a1_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 5) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 642 || i == 594 || i == 546 || i == 498 || i == 450 || i == 402 || i == 354 || i == 306 || i == 258 || i == 210 || i == 162 || i == 701 || i == 700 || i == 699 || i == 698 || i == 697 || i == 696 || i == 695 || i == 694 || i == 693 || i == 692 || i == 691 || i == 654 || i == 606 || i == 558 || i == 510 || i == 462 || i == 414 || i == 366 || i == 318 || i == 270 || i == 222 || i == 174 || i == 125 || i == 124 || i == 123 || i == 122 || i == 121 || i == 120 || i == 119 || i == 118 || i == 117 || i == 116 || i == 115) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !b3_used1 && !b3_used2) {
            b3_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 6) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 2178 || i == 2130 || i == 2082 || i == 2034 || i == 1986 || i == 1938 || i == 1890 || i == 1842 || i == 1794 || i == 1746 || i == 1698 || i == 2237 || i == 2236 || i == 2235 || i == 2234 || i == 2233 || i == 2232 || i == 2231 || i == 2230 || i == 2229 || i == 2228 || i == 2227 || i == 2190 || i == 2142 || i == 2094 || i == 2046 || i == 1998 || i == 1950 || i == 1902 || i == 1854 || i == 1806 || i == 1758 || i == 1710 || i == 1661 || i == 1660 || i == 1659 || i == 1658 || i == 1657 || i == 1656 || i == 1655 || i == 1654 || i == 1653 || i == 1652 || i == 1651) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !b1_used1 && !b1_used2) {
            b1_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 7) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1394 || i == 1346 || i == 1298 || i == 1250 || i == 1202 || i == 1154 || i == 1106 || i == 1058 || i == 1010 || i == 962 || i == 914 || i == 1453 || i == 1452 || i == 1451 || i == 1450 || i == 1449 || i == 1448 || i == 1447 || i == 1446 || i == 1445 || i == 1444 || i == 1443 || i == 1406 || i == 1358 || i == 1310 || i == 1262 || i == 1214 || i == 1166 || i == 1118 || i == 1070 || i == 1022 || i == 974 || i == 926 || i == 877 || i == 876 || i == 875 || i == 874 || i == 873 || i == 872 || i == 871 || i == 870 || i == 869 || i == 868 || i == 867) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !c2_used1 && !c2_used2) {
            c2_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 8) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 626 || i == 578 || i == 530 || i == 482 || i == 434 || i == 386 || i == 338 || i == 290 || i == 242 || i == 194 || i == 146 || i == 685 || i == 684 || i == 683 || i == 682 || i == 681 || i == 680 || i == 679 || i == 678 || i == 677 || i == 676 || i == 675 || i == 638 || i == 590 || i == 542 || i == 494 || i == 446 || i == 398 || i == 350 || i == 302 || i == 254 || i == 206 || i == 158 || i == 109 || i == 108 || i == 107 || i == 106 || i == 105 || i == 104 || i == 103 || i == 102 || i == 101 || i == 100 || i == 99) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !c3_used1 && !c3_used2) {
            c3_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
        if (status == 9) {
          for (int i = 0; i < MAXLED; i++) {
            if (i == 1682 || i == 2221 || i == 2220 || i == 2162 || i == 2114 || i == 2066 || i == 2018 || i == 1970 || i == 1922 || i == 1874 || i == 1826 || i == 1778 || i == 1730 || i == 2219 || i == 2218 || i == 2217 || i == 2216 || i == 2215 || i == 2214 || i == 2213 || i == 2212 || i == 2211 || i == 2174 || i == 2126 || i == 2078 || i == 2030 || i == 1982 || i == 1934 || i == 1886 || i == 1838 || i == 1790 || i == 1742 || i == 1694 || i == 1645 || i == 1644 || i == 1643 || i == 1642 || i == 1641 || i == 1640 || i == 1639 || i == 1638 || i == 1637 || i == 1636 || i == 1635) {
              led.setPixelColor(i, led.Color(0, 0, 255));
            }
          }
          led.show();
          if (status_pressed1 == 1 && !c1_used1 && !c1_used2) {
            c1_used2 = true;
            beginner = false;
            count_no_winner += 1;
          }
        }
      }
    }
  }
}
//



void game_COIN_COLLECT() {
  if (select == 3) {
    coin();
    check_pos();
    check_win_coin_collect();
    easter_counter = 0;
  }
}


//zur bewegung der Spielfigur in JUMP AND RUN
void jumper() {
  nunchuck1.readData();
  nunchuck2.readData();
  nunchuck3.readData();
  for (int i = 90; i < 190; i++) {
    if (i == 140 || i == 92) {
      led.setPixelColor(i + jump1 + move1, led.Color(255, 0, 0));
    }
  }
  if (nunchuck1.getJoyY() < 80 && jump1 > 0) {
    jump1 -= 96;
  }
  if (nunchuck1.getJoyY() > 180 && jump1 < 572) {
    jump1 += 96;
  }

  for (int i = 859; i < 909; i++) {
    if (i == 860 || i == 908) {
      led.setPixelColor(i + jump2, led.Color(0, 255, 0));
    }
  }
  if (nunchuck2.getJoyY() < 80 && jump2 > 0) {
    jump2 -= 96;
  }
  if (nunchuck2.getJoyY() > 180 && jump2 < 572) {
    jump2 += 96;
  }

  for (int i = 1627; i < 1677; i++) {
    if (i == 1628 || i == 1676) {
      led.setPixelColor(i + jump3, led.Color(0, 0, 255));
    }
  }
  if (nunchuck3.getJoyY() < 80 && jump3 > 0) {
    jump3 -= 96;
  }
  if (nunchuck3.getJoyY() > 180 && jump3 < 572) {
    jump3 += 96;
  }
}

//zeigt an wenn eine Collision entdeckt wurde
void collision() {
  if (coll_detect_one) {
    for (int i = 0; i < 768; i++) {
      led.setPixelColor(i, led.Color(255, 0, 0));
    }
  }
  if (coll_detect_two) {
    for (int i = 768; i < 1536; i++) {
      led.setPixelColor(i, led.Color(0, 255, 0));
    }
  }
  if (coll_detect_three) {
    for (int i = 1536; i < 2304; i++) {
      led.setPixelColor(i, led.Color(0, 0, 255));
    }
  }
}

void win_JUMP_AND_RUN() {
  if (coll_detect_one && coll_detect_two) {
    win_row_three = true;
  }
  if (coll_detect_one && coll_detect_three) {
    win_row_two = true;
  }
  if (coll_detect_two && coll_detect_three) {
    win_row_one = true;
  }
  if (win_row_one) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(255, 0, 0));
    }
    led.show();
    new_block = true;
    ran_num = 0;
    num_of_total_rows = 0;
    row_speed = 25;
    row_move_speed = 1;
    counter_new_row = 0;
    coll_detect_one = false;
    coll_detect_two = false;
    coll_detect_three = false;
    win_row_one = false;
    win_row_two = false;
    win_row_three = false;
    led_row1 = 0;
    led_row2 = 0;
    led_row3 = 0;
    led_row4 = 0;
    led_row5 = 0;
    row1 = false;
    row2 = false;
    row3 = false;
    row4 = false;
    blackout_time = false;
    delay(1000);
  }
  if (win_row_two) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 255, 0));
    }
    led.show();
    new_block = true;
    ran_num = 0;
    num_of_total_rows = 0;
    row_speed = 25;
    row_move_speed = 1;
    counter_new_row = 0;
    coll_detect_one = false;
    coll_detect_two = false;
    coll_detect_three = false;
    win_row_one = false;
    win_row_two = false;
    win_row_three = false;
    led_row1 = 0;
    led_row2 = 0;
    led_row3 = 0;
    led_row4 = 0;
    led_row5 = 0;
    row1 = false;
    row2 = false;
    row3 = false;
    row4 = false;
    blackout_time = false;
    delay(1000);
  }
  if (win_row_three) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 255));
    }
    led.show();
    new_block = true;
    ran_num = 0;
    num_of_total_rows = 0;
    row_speed = 25;
    row_move_speed = 1;
    counter_new_row = 0;
    coll_detect_one = false;
    coll_detect_two = false;
    coll_detect_three = false;
    win_row_one = false;
    win_row_two = false;
    win_row_three = false;
    led_row1 = 0;
    led_row2 = 0;
    led_row3 = 0;
    led_row4 = 0;
    led_row5 = 0;
    row1 = false;
    row2 = false;
    row3 = false;
    row4 = false;
    blackout_time = false;
    delay(1000);
  }
}


void game_JUMP_AND_RUN() {
  if (select == 4) {
    easter_counter = 0;
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 0));
    }
    for (int i = 0; i < MAXLED; i++) {
      if (i <= 47) {
        led.setPixelColor(i, led.Color(255, 255, 255));
      }
      if (i >= 720 && i <= 767) {
        led.setPixelColor(i, led.Color(255, 255, 255));
      }
      if (i >= 768 && i <= 815) {
        led.setPixelColor(i, led.Color(255, 255, 255));
      }
      if (i <= 1535 && i >= 1488) {
        led.setPixelColor(i, led.Color(255, 255, 255));
      }
      if (i >= 1536 && i <= 1583) {
        led.setPixelColor(i, led.Color(255, 255, 255));
      }
      if (i <= 2303 && i >= 2256) {
        led.setPixelColor(i, led.Color(255, 255, 255));
      }
    }

    //Entscheidet zufällig welcher Block als nächstes angezeigt wird zudem wird solang eine neu zufällige zahl
    //erzeugt bis sie unterschiedlich zur vorherigen ist (siehe: While loop)
    if (new_block) {
      ran_num = (1 + rand() % 4);
      while (check_for_double == ran_num) {
        ran_num = (1 + rand() % 4);
      }
      check_for_double = ran_num;
      if (ran_num == 1) {
        row1 = true;
      } else if (ran_num == 2) {
        row2 = true;
      } else if (ran_num == 3) {
        row3 = true;
      } else if (ran_num == 4) {
        row4 = true;
      }
      new_block = false;
    }
    // sorgt dafür das sich die Blöcke richtung spieler bewegen, Überprüft ob der Spieler mit den Bewegten Blöcken kontakt hat
    if (row1) {
      for (int i = 48; i < 2065; i++) {
        if (i == 48 || i == 96 || i == 144 || i == 192 || i == 240 || i == 288 || i == 336 || i == 384 || i == 432 || i == 480 || i == 528) {
          led.setPixelColor(i + led_row1, led.Color(255, 255, 255));
          if ((i + led_row1) == (92 + jump1) || (i + led_row1) == (140 + jump1)) {
            coll_detect_one = true;
          }
        }
        if (i == 816 || i == 864 || i == 912 || i == 960 || i == 1008 || i == 1056 || i == 1104 || i == 1152 || i == 1200 || i == 1248 || i == 1296) {
          led.setPixelColor(i + led_row1, led.Color(255, 255, 255));
          if ((i + led_row1) == (860 + jump2) || (i + led_row1) == (908 + jump2)) {
            coll_detect_two = true;
          }
        }
        if (i == 1584 || i == 1632 || i == 1680 || i == 1728 || i == 1776 || i == 1824 || i == 1872 || i == 1920 || i == 1968 || i == 2016 || i == 2064) {
          led.setPixelColor(i + led_row1, led.Color(255, 255, 255));
          if ((i + led_row1) == (1628 + jump3) || (i + led_row1) == (1676 + jump3)) {
            coll_detect_three = true;
          }
        }
      }
      led_row1 = led_row1 + row_move_speed;
    }
    if (row2) {
      for (int i = 192; i < 2209; i++) {
        if (i == 192 || i == 240 || i == 288 || i == 336 || i == 384 || i == 432 || i == 480 || i == 528 || i == 672 || i == 624 || i == 576) {
          led.setPixelColor(i + led_row2, led.Color(255, 255, 255));
          if ((i + led_row2) == (92 + jump1) || (i + led_row2) == (140 + jump1)) {
            coll_detect_one = true;
          }
        }
        if (i == 1440 || i == 1392 || i == 1344 || i == 1296 || i == 1248 || i == 1200 || i == 1152 || i == 1104 || i == 1056 || i == 1008 || i == 960) {
          led.setPixelColor(i + led_row2, led.Color(255, 255, 255));
          if ((i + led_row2) == (860 + jump2) || (i + led_row2) == (908 + jump2)) {
            coll_detect_two = true;
          }
        }
        if (i == 2208 || i == 2160 || i == 2112 || i == 2064 || i == 2016 || i == 1968 || i == 1920 || i == 1872 || i == 1824 || i == 1776 || i == 1728) {
          led.setPixelColor(i + led_row2, led.Color(255, 255, 255));
          if ((i + led_row2) == (1628 + jump3) || (i + led_row2) == (1676 + jump3)) {
            coll_detect_three = true;
          }
        }
      }
      led_row2 = led_row2 + row_move_speed;
    }
    if (row3) {
      for (int i = 384; i < 2209; i++) {
        if (i == 384 || i == 432 || i == 480 || i == 528 || i == 672 || i == 624 || i == 576) {
          led.setPixelColor(i + led_row3, led.Color(255, 255, 255));
          if ((i + led_row3) == (92 + jump1) || (i + led_row3) == (140 + jump1)) {
            coll_detect_one = true;
          }
        }
        if (i == 1440 || i == 1392 || i == 1344 || i == 1296 || i == 1248 || i == 1200 || i == 1152) {
          led.setPixelColor(i + led_row3, led.Color(255, 255, 255));
          if ((i + led_row3) == (860 + jump2) || (i + led_row3) == (908 + jump2)) {
            coll_detect_two = true;
          }
        }
        if (i == 2208 || i == 2160 || i == 2112 || i == 2064 || i == 2016 || i == 1968 || i == 1920) {
          led.setPixelColor(i + led_row3, led.Color(255, 255, 255));
          if ((i + led_row3) == (1628 + jump3) || (i + led_row3) == (1676 + jump3)) {
            coll_detect_three = true;
          }
        }
      }
      led_row3 = led_row3 + row_move_speed;
    }
    if (row4) {
      for (int i = 48; i < 1729; i++) {
        if (i == 48 || i == 96 || i == 144 || i == 192) {
          led.setPixelColor(i + led_row4, led.Color(255, 255, 255));
          if ((i + led_row4) == (92 + jump1) || (i + led_row4) == (140 + jump1)) {
            coll_detect_one = true;
          }
        }
        if (i == 816 || i == 864 || i == 912 || i == 960) {
          led.setPixelColor(i + led_row4, led.Color(255, 255, 255));
          if ((i + led_row4) == (860 + jump2) || (i + led_row4) == (908 + jump2)) {
            coll_detect_two = true;
          }
        }
        if (i == 1584 || i == 1632 || i == 1680 || i == 1728) {
          led.setPixelColor(i + led_row4, led.Color(255, 255, 255));
          if ((i + led_row4) == (1628 + jump3) || (i + led_row4) == (1676 + jump3)) {
            coll_detect_three = true;
          }
        }
      }
      led_row4 = led_row4 + row_move_speed;
    }
    /*******************************************************************************/
    // Ausgeklammert weil ab 5 reihen die so programmiert sind die Leds nicht mehr richtig ablaufen und angezeigt werden, bis 4 reihen funktioniert die Programierung
    /******************************************************************************/
    /*if (row5) {
      for (int i = 48; i < 1633; i++) {
        if (i == 48 || i == 96) {
          led.setPixelColor(i + led_row5, led.Color(255, 255, 255));
          if ((i + led_row5) == (92 + jump1) || (i + led_row5) == (140 + jump1)) {
            coll_detect_one = true;
          }
        }
        if (i == 816 || i == 864) {
          led.setPixelColor(i + led_row5, led.Color(255, 255, 255));
          if ((i + led_row5) == (860 + jump2) || (i + led_row5) == (908 + jump2)) {
            coll_detect_two = true;
          }
        }
        if (i == 1584 || i == 1632) {
          led.setPixelColor(i + led_row5, led.Color(255, 255, 255));
          if ((i + led_row5) == (1628 + jump3) || (i + led_row5) == (1676 + jump3)) {
            coll_detect_three = true;
          }
        }
      }
      for (int i = 240; i < 2209; i++) {
        if (i == 240 || i == 288 || i == 336 || i == 384 || i == 432 || i == 480 || i == 528 || i == 576 || i == 624 || i == 672) {
          led.setPixelColor(i + (led_row5 + 3), led.Color(255, 255, 255));
          if ((i + led_row5 + 3) == (92 + jump1) || (i + led_row5 + 3) == (140 + jump1)) {
            coll_detect_one = true;
          }
        }
        if (i == 1440 || i == 1392 || i == 1344 || i == 1296 || i == 1248 || i == 1200 || i == 1152 || i == 1104 || i == 1056 || i == 1008) {
          led.setPixelColor(i + (led_row5 + 3), led.Color(255, 255, 255));
          if ((i + led_row5 + 3) == (860 + jump2) || (i + led_row5 + 3) == (908 + jump2)) {
            coll_detect_two = true;
          }
        }
        if (i == 2208 || i == 2160 || i == 2112 || i == 2064 || i == 2016 || i == 1968 || i == 1920 || i == 1872 || i == 1824 || i == 1776) {
          led.setPixelColor(i + (led_row5 + 3), led.Color(255, 255, 255));
          if ((i + led_row5 + 3) == (1628 + jump3) || (i + led_row5 + 3) == (1676 + jump3)) {
            coll_detect_three = true;
          }
        }
      }
      led_row5 = led_row5 + row_move_speed;
    }*/

    //Entscheidet wann eine neue Block reihe erzeugt wird (row_speed ist dafür entscheident -> desto kleiner rwo_speed desto schneller)
    if (num_of_total_rows >= 1) {
      if (counter_new_row >= row_speed) {
        new_block = true;
        counter_new_row = 0;
      }
      counter_new_row++;
    }
    //erhöht die geschwindigkeit(row_move_speed) je nach dem wie viele block reihen insgesamt am ende angekommen sind und wie viele
    //Block reihen gleichzeitig auf dem Tisch erscheinen können(row_speed)
    //legt fest wann blackout zeit zum Spiel hinzugefügt wird
    if (num_of_total_rows >= 4 && row_speed > 17) {
      row_speed = 15;
    } else if (num_of_total_rows >= 8 && row_speed > 14) {
      row_speed = 11;
      row_move_speed = 2;
    } else if (num_of_total_rows >= 15 && row_speed > 10) {
      row_speed = 7;
    } else if (num_of_total_rows >= 30 && row_speed > 6) {
      row_speed = 3;
      row_move_speed = 3;
    }
    if (num_of_total_rows >= 120) {
      blackout_time = true;
    }
    //zudem wird num_of_toatl_rows erhöht -> die schnelligkeit der Blöcke hängt davon ab
    //led_row wird gelöscht wodurch sie neu angezeigt werden kann
    if (led_row1 >= 48) {
      row1 = false;
      led_row1 = 0;
      num_of_total_rows += 1;
      blackout_count = 0;
    }
    if (led_row2 >= 48) {
      row2 = false;
      led_row2 = 0;
      num_of_total_rows += 1;
      blackout_count = 0;
    }
    if (led_row3 >= 48) {
      row3 = false;
      led_row3 = 0;
      num_of_total_rows += 1;
      blackout_count = 0;
    }
    if (led_row4 >= 48) {
      row4 = false;
      led_row4 = 0;
      num_of_total_rows += 1;
      blackout_count = 0;
    }

    jumper();
    collision();
    win_JUMP_AND_RUN();
    //startet blackout zeit
    if (blackout_time) {
      if (blackout_count >= 12) {
        for (int i = 0; i < MAXLED; i++) {
          led.setPixelColor(i, led.Color(0, 0, 0));
        }
      }
      blackout_count++;
    }
    ran_num = 0;
    led.show();
  }
}


//sorgt für die Bewegung der Spieler und überprüft ob diese sich  im Ziel befinden
void stop_and_go_player() {
  nunchuck1.readData();
  nunchuck2.readData();
  nunchuck3.readData();
  nunchuck4.readData();
  if (nunchuck1.getJoyY() > 180 && move_speed == 0) {
    if (!red) {
      move_squid_p1 += 48;
    }
    check_for_move1 += 48;
  }
  if (!failure_p1) {
    for (int i = 9; i < 109; i++) {
      if (i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 59 || i == 60 || i == 61 || i == 108) {
        led.setPixelColor(i + move_squid_p1, led.Color(255, 0, 0));
      }
      if ((i + move_squid_p1) >= 1884) {
        win_p1 = true;
      }
    }
  }
  if (nunchuck2.getJoyY() > 180 && move_speed == 0) {
    if (!red) {
      move_squid_p2 += 48;
    }
    check_for_move2 += 48;
  }
  if (!failure_p2) {
    for (int i = 19; i < 117; i++) {
      if (i == 20 || i == 67 || i == 69 || i == 116) {
        led.setPixelColor(i + move_squid_p2, led.Color(0, 255, 0));
      }
      if ((i + move_squid_p2) >= 1892) {
        win_p2 = true;
      }
    }
  }
  if (nunchuck3.getJoyY() > 180 && move_speed == 0) {
    if (!red) {
      move_squid_p3 += 48;
    }
    check_for_move3 += 48;
  }
  if (!failure_p3) {
    for (int i = 27; i < 126; i++) {
      if (i == 28 || i == 74 || i == 76 || i == 78 || i == 123 || i == 124 || i == 125) {
        led.setPixelColor(i + move_squid_p3, led.Color(0, 0, 255));
      }
      if ((i + move_squid_p3) >= 1900) {
        win_p3 = true;
      }
    }
  }
  if (nunchuck4.getJoyY() > 180 && move_speed == 0) {
    if (!red) {
      move_squid_p4 += 48;
    }
    check_for_move4 += 48;
  }
  if (!failure_p4) {
    for (int i = 34; i < 134; i++) {
      if (i == 35 || i == 37 || i == 84 || i == 131 || i == 133) {
        led.setPixelColor(i + move_squid_p4, led.Color(255, 255, 255));
      }
      if ((i + move_squid_p4) >= 1907) {
        win_p4 = true;
      }
    }
  }
  if (move_speed == 0) {
    move_speed = 3;
  }
  if (move_speed > 0) {
    move_speed--;
  }
}
//überprüft ob sich bei rot bewegt wurde
void check_for_failure() {
  if (red && check_for_move1 > move_squid_p1) {
    failure_p1 = true;
  }
  if (red && check_for_move2 > move_squid_p2) {
    failure_p2 = true;
  }
  if (red && check_for_move3 > move_squid_p3) {
    failure_p3 = true;
  }
  if (red && check_for_move4 > move_squid_p4) {
    failure_p4 = true;
  }
}

void check_for_win() {
  if (failure_p1 && failure_p2 && failure_p3 && failure_p4) {
    failure_p1 = false;
    failure_p2 = false;
    failure_p3 = false;
    failure_p4 = false;
    check_for_move1 = 0;
    move_squid_p1 = 0;
    check_for_move2 = 0;
    move_squid_p2 = 0;
    check_for_move3 = 0;
    move_squid_p3 = 0;
    check_for_move4 = 0;
    move_squid_p4 = 0;
    green = true;
    red = false;
    yellow = false;
    ran_timer1 = 0;
    ran_timer2 = 0;
    ran_timer3 = 0;
  }
  if (win_p1) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(255, 0, 0));
    }
    led.show();
    delay(1000);
    failure_p1 = false;
    failure_p2 = false;
    failure_p3 = false;
    failure_p4 = false;
    check_for_move1 = 0;
    move_squid_p1 = 0;
    check_for_move2 = 0;
    move_squid_p2 = 0;
    check_for_move3 = 0;
    move_squid_p3 = 0;
    check_for_move4 = 0;
    move_squid_p4 = 0;
    green = true;
    red = false;
    yellow = false;
    ran_timer1 = 0;
    ran_timer2 = 0;
    ran_timer3 = 0;
    win_p1 = false;
  }
  if (win_p2) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 255, 0));
    }
    led.show();
    delay(1000);
    failure_p1 = false;
    failure_p2 = false;
    failure_p3 = false;
    failure_p4 = false;
    check_for_move1 = 0;
    move_squid_p1 = 0;
    check_for_move2 = 0;
    move_squid_p2 = 0;
    check_for_move3 = 0;
    move_squid_p3 = 0;
    check_for_move4 = 0;
    move_squid_p4 = 0;
    green = true;
    red = false;
    yellow = false;
    ran_timer1 = 0;
    ran_timer2 = 0;
    ran_timer3 = 0;
    win_p2 = false;
  }
  if (win_p3) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 255));
    }
    led.show();
    delay(1000);
    failure_p1 = false;
    failure_p2 = false;
    failure_p3 = false;
    failure_p4 = false;
    check_for_move1 = 0;
    move_squid_p1 = 0;
    check_for_move2 = 0;
    move_squid_p2 = 0;
    check_for_move3 = 0;
    move_squid_p3 = 0;
    check_for_move4 = 0;
    move_squid_p4 = 0;
    green = true;
    red = false;
    yellow = false;
    ran_timer1 = 0;
    ran_timer2 = 0;
    ran_timer3 = 0;
    win_p3 = false;
  }
  if (win_p4) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(255, 255, 255));
    }
    led.show();
    delay(1000);
    failure_p1 = false;
    failure_p2 = false;
    failure_p3 = false;
    failure_p4 = false;
    check_for_move1 = 0;
    move_squid_p1 = 0;
    check_for_move2 = 0;
    move_squid_p2 = 0;
    check_for_move3 = 0;
    move_squid_p3 = 0;
    check_for_move4 = 0;
    move_squid_p4 = 0;
    green = true;
    red = false;
    yellow = false;
    ran_timer1 = 0;
    ran_timer2 = 0;
    ran_timer3 = 0;
    win_p4 = false;
  }
}

//setzt die zufälligen timer um zu entscheiden wann und wie lange welche farbe angezeigt wird
void game_STOP_AND_GO() {
  if (select == 5) {
    easter_counter = 0;
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 0));
    }
    if (ran_timer1 == 0 && green) {
      ran_timer1 = (15 + rand() % 10);
    }
    if (ran_timer2 == 0 && yellow) {
      ran_timer2 = (3 + rand() % 7);
    }
    if (ran_timer3 == 0 && red) {
      ran_timer3 = (10 + rand() % 20);
    }
    if (ran_timer1 > 0) {
      for (int i = 1776; i < 2304; i++) {
        led.setPixelColor(i, led.Color(0, 255, 0));
      }
      if (ran_timer1 == 1) {
        green = false;
        yellow = true;
        ran_timer1 = 0;
      }
    }
    if (ran_timer2 > 0) {
      for (int i = 1776; i < 2304; i++) {
        led.setPixelColor(i, led.Color(255, 255, 0));
      }
      if (ran_timer2 == 1) {
        yellow = false;
        red = true;
        ran_timer2 = 0;
      }
    }
    if (ran_timer3 > 0) {
      for (int i = 1776; i < 2304; i++) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
      if (ran_timer3 == 1) {
        green = true;
        red = false;
        ran_timer3 = 0;
      }
    }
    if (ran_timer1 > 0) {
      ran_timer1--;
    }
    if (ran_timer2 > 0) {
      ran_timer2--;
    }
    if (ran_timer3 > 0) {
      ran_timer3--;
    }
    stop_and_go_player();
    check_for_failure();
    check_for_win();
    led.show();
  }
}


void follow_path_player(){
  nunchuck1.readData();
  led.setPixelColor(start_position+follow_direction, led.Color(255,255,255));
  if(nunchuck1.getJoyX() < 80){
    follow_direction++;
  }
  if(nunchuck1.getJoyX() > 180){
    follow_direction--;
  }
  if(nunchuck1.getJoyY() < 80){
    follow_direction += 48;
  }
  if(nunchuck1.getJoyY() > 180){
    follow_direction -= 48;
  }
}

void generate_path(){
  if(max_path_length < length){
    ran_path_num = (1+ rand() % 2303);
    led.setPixelColor(ran_path_num, led.Color(255,0,0));
  }
}

void game_FOLLOW_PATH(){
  if(select == 6){
    for(int i = 0; i < MAXLED; i++){
      led.setPixelColor(i,led.Color(0,0,0));
    }
    follow_path_player();
    led.show();
  }
}



void rainbow(int wait){
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256){
    for(int i = 0; i < 815; i++){
      int pixelHue = firstPixelHue + (i * 65536L / led.numPixels());
      led.setPixelColor(i,led.gamma32(led.ColorHSV(pixelHue)));
    }
    led.show();
    delay(wait);
  }
}


void easter_egg() {  //Credits
nunchuck3.readData();
  if (nunchuck3.getButtonZ() == 1) {
    easter_counter++;
  }
  if (easter_counter > 100) {
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 0));
    }
    for (int i = 0; i < MAXLED; i++) {
      if (i == 1519 || i == 1518 || i == 1471 || i == 1470 || i == 1423 || i == 1422 || i == 1375 || i == 1374 || i == 1327 || i == 1326 || i == 1279 || i == 1278 || i == 1231 || i == 1230 || i == 1183 || i == 1182 || i == 1135 || i == 1134 || i == 1087 || i == 1086 || i == 1039 || i == 1038 || i == 991 || i == 990 || i == 943 || i == 942 || i == 895 || i == 894 || i == 1473 || i == 1472 || i == 1425 || i == 1424 || i == 1379 || i == 1378 || i == 1331 || i == 1330 || i == 1285 || i == 1284 || i == 1237 || i == 1236 || i == 1383 || i == 1382 || i == 1335 || i == 1334 || i == 1481 || i == 1480 || i == 1433 || i == 1432 || i == 1531 || i == 1530 || i == 1483 || i == 1482 || i == 1435 || i == 1434 || i == 1387 || i == 1386 || i == 1339 || i == 1338 || i == 1291 || i == 1290 || i == 1243 || i == 1242 || i == 1195 || i == 1194 || i == 1147 || i == 1146 || i == 1099 || i == 1098 || i == 1051 || i == 1050 || i == 1003 || i == 1002 || i == 955 || i == 954 || i == 907 || i == 906) {
        led.setPixelColor(i, led.Color(255, 0, 0));
      }
      if (i == 1501 || i == 1500 || i == 1499 || i == 1498 || i == 1497 || i == 1496 || i == 1495 || i == 1494 || i == 1493 || i == 1492 || i == 1453 || i == 1452 || i == 1451 || i == 1450 || i == 1449 || i == 1448 || i == 1447 || i == 1446 || i == 1445 || i == 1444 || i == 1397 || i == 1396 || i == 1349 || i == 1348 || i == 1301 || i == 1300 || i == 1253 || i == 1252 || i == 1205 || i == 1204 || i == 1157 || i == 1156 || i == 1109 || i == 1108 || i == 1061 || i == 1060 || i == 1013 || i == 1012 || i == 965 || i == 964 || i == 925 || i == 924 || i == 923 || i == 922 || i == 921 || i == 920 || i == 919 || i == 918 || i == 877 || i == 876 || i == 875 || i == 874 || i == 873 || i == 872 || i == 871 || i == 870 || i == 917) {
        led.setPixelColor(i, led.Color(0, 255, 0));
      }
      if (i == 1514 || i == 1513 || i == 1466 || i == 1465 || i == 1418 || i == 1417 || i == 1370 || i == 1369 || i == 1322 || i == 1321 || i == 1274 || i == 1273 || i == 1226 || i == 1225 || i == 1178 || i == 1177 || i == 1130 || i == 1129 || i == 1082 || i == 1081 || i == 1034 || i == 1033 || i == 986 || i == 985 || i == 938 || i == 937 || i == 890 || i == 889 || i == 1512 || i == 1511 || i == 1510 || i == 1509 || i == 1508 || i == 1507 || i == 1506 || i == 1505 || i == 1464 || i == 1463 || i == 1462 || i == 1461 || i == 1460 || i == 1459 || i == 1458 || i == 1457 || i == 1272 || i == 1271 || i == 1270 || i == 1269 || i == 1268 || i == 1267 || i == 1266 || i == 1265 || i == 1224 || i == 1223 || i == 1222 || i == 1221 || i == 1220 || i == 1219 || i == 1218 || i == 1217) {
        led.setPixelColor(i, led.Color(0, 0, 255));
      }
      if (i == 1963 || i == 1962 || i == 1961 || i == 1960 || i == 1771 || i == 1770 || i == 1769 || i == 1768 || i == 1915 || i == 1867 || i == 1819 || i == 1957 || i == 1909 || i == 1861 || i == 1813 || i == 1765 || i == 1860 || i == 1859 || i == 1811 || i == 1762 || i == 1954 || i == 1906 || i == 1956 || i == 1955 || i == 1951 || i == 1903 || i == 1855 || i == 1807 || i == 1759 || i == 1854 || i == 1853 || i == 1852 || i == 1950 || i == 1949 || i == 1948 || i == 1758 || i == 1757 || i == 1756 || i == 1945 || i == 1897 || i == 1849 || i == 1801 || i == 1753 || i == 1752 || i == 1751 || i == 1944 || i == 1943 || i == 1894 || i == 1846 || i == 1798 || i == 1939 || i == 1891 || i == 1843 || i == 1795 || i == 1747 || i == 1936 || i == 1935 || i == 1934 || i == 1933 || i == 1932 || i == 1886 || i == 1838 || i == 1790 || i == 1742 || i == 1929 || i == 1928 || i == 1927 || i == 1926 || i == 1833 || i == 1832 || i == 1831 || i == 1830 || i == 1737 || i == 1736 || i == 1735 || i == 1734 || i == 1782 || i == 1881 || i == 1923 || i == 1922 || i == 1875 || i == 1874 || i == 1779 || i == 1778 || i == 1731 || i == 1730) {
        led.setPixelColor(i, led.Color(255, 255, 255));
      }
    }
    rainbow(5);
    led.show();
  }
}


//Ruft alle Haupt funktionen auf und erhöht die variable des standby_Timer (diese funktioniert auch innerhalb von Spielen wenn nichts gedrückt wird)
//Loop wird genau wie Setup in jedem Programm benötigt
//void loop wird AUTOMATISCH immer wieder aufgerufen
void loop() {
  start_program();
  reset();
  game_ONE_LED_RACE();
  game_TWO_TIC_TAC_TOE();
  game_COIN_COLLECT();
  game_JUMP_AND_RUN();
  game_STOP_AND_GO();
  game_FOLLOW_PATH();
  standby_Timer++;
}
