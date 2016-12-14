#include <U8glib.h>
#include "key.h"//声明自定义的库
#include "arduino.h"
#define key_pin 6
#define INTERVAL_LCD             20             //定义OLED刷新时间间隔  
int a;
unsigned long lcd_time = millis();                 //OLED刷新时间计时器
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);     //设置OLED型号  
//-------字体设置，大、中、小
#define setFont_L u8g.setFont(u8g_font_7x13)
#define setFont_M u8g.setFont(u8g_font_fixed_v0r)
#define setFont_S u8g.setFont(u8g_font_fixed_v0r)
#define setFont_SS u8g.setFont(u8g_font_fub25n)

long randNumber;
 
void setup(){
  Serial.begin(9600);
pinMode(key_pin, INPUT);//定义引脚6为输入模式，用来接收信号


//如果模拟输入引脚0为断开，随机的模拟噪声
//将会调用randomSeed()函数在每次代码运行时生成
//不同的种子数值。
//randomSeed()将随机打乱random函数。
  randomSeed(analogRead(0));
}
 
void loop() {
//
  
  
  if (key_get(key_pin, 0))//调用自定义库key.h中的函数
{
  Serial.println(a);
  delay(5000);
  //Serial.println("ok");  
}
  else {
    randNumber = random(300);
  Serial.println(randNumber);  
 
//打印一个10到19之间的随机数
  randNumber = random(10, 20);
  a=randNumber;
  Serial.println(randNumber);
  
  u8g.firstPage();
    do {
        setFont_L;
        u8g.setPrintPos(4, 16);
        u8g.print(randNumber);
    }while( u8g.nextPage() );

  delay(1);
  }
  
}
