![hds-logo_0](https://user-images.githubusercontent.com/80938836/111745948-ea8a5f00-88bf-11eb-83e5-bc22db83b2fd.png)
# HandySense Board 
![](https://komarev.com/ghpvc/?username=your-github-HandySense-Blueprint&color=brightgreen) 

* HandySense คือ ระบบอุปกรณ์ IOT สำหรับเกษตรอัจฉริยะที่สามารถแสดงค่าข้อมูล ปัจจัยในการควบคุมผลผลิตทางการเกษตร โดยใช้เทคโนโลยีเซนเซอร์เข้ามาช่วยในกระบวนการเพาะปลูกซึ่งช่วยให้เกษตรกรสามารถควบคุมสภาวะแวดล้อมในการปลูกได้ตั้งแต่เริ่มต้นส่งผลให้สามารถควบคุมคุณภาพและประเมินปริมาณผลผลิต 
* รวมถึงช่วยเรื่องการเพิ่มคุณค่าของผลผลิตได้โดยใช้การควบคุมกระบวนการเพาะปลูกเพื่อให้ผลผลิตออกในช่วงที่มีความต้องการหรือผลผลิตขาดแคลนรวมถึงการช่วยเกษตรกรนำองค์ความรู้ที่เกิดจากทักษะที่ไม่สามารถถ่ายทอดให้เข้าใจได้เนื่องจากเป็นภูมิปัญญาและเป็นการทำเกษตรกรรมแบบวิถีชาวบ้านโดยการลองผิดลองถูกหรือเป็นองค์ความรู้ที่สืบทอดต่อกัน
 
# สารบัญ
1. องค์ประกอบของบอร์ด HandySense 
2. ไฟล์ PCB และ SCH 
3. BluePrint (GerberFile)
4. คู่มือการใช้งาน

# 1. องค์ประกอบของบอร์ด HandySense 
โดย HandySense Board ประกอบด้วยอินเตอร์เฟสการสื่อสารหลักเป็น I2C, SPI, Analog, WIFI 
* I2C ต่อ Connector ออกมาให้ใช้งาน 2 ชุด (+5V)  
* Analog ต่อ Connector ออกมาให้ใช้งาน 3 pin ได้แก่ IO36(A0), IO39(A3), IO32(A4)
* SPI ขา CS/SS เป็น IO5 บนบอร์ดไม่ได้ต่ออุปกรณ์ แต่ต่อกับ IDC10 (block 10 pin) 
* ส่วน WIFI สื่อสารข้อมูลกับ Server เป็นหลัก
รายละเอียดแสดงดังภาพ (*แสดงพอสังเขป โดยลเอียดอ่านคู่มือเพิ่มเติม)

![detailHS](https://github.com/HandySense/HandySense/blob/main/detailHS.PNG)

# 2. ไฟล์ PCB และ SCH 
สำหรับ HandySense version นี้ออกแบบด้วยโปรแกรม Autodesk Eagle ซึ่งไฟล์สามารถกดดาวน์โหลดได้ด้านบน 

* ไฟล์ .sch
![sch](https://github.com/HandySense/HandySense/blob/main/sch.png)

* ไฟล์ .brd (PCB  layout)
![sch](https://github.com/HandySense/HandySense/blob/main/pcb.png)

# 3. BluePrint (Gerber File)
สำหรับ BluePrint จะ save เป็น Gerber File ที่สามารถนำไปสั่งผลิตได้ โดยไม่ต้องปรับแก้อะไร สามารถดาวน์โหลดได้ด้านบน

* Gerber File 
![gerber](https://github.com/HandySense/HandySense/blob/main/gerber.png)


# Open Hardware Facts
![](https://github.com/HandySense/HandySense/blob/main/os.PNG)

