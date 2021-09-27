![hds-logo_0](https://user-images.githubusercontent.com/80938836/111745948-ea8a5f00-88bf-11eb-83e5-bc22db83b2fd.png)
# HandySense Board 
![](https://komarev.com/ghpvc/?username=your-github-HandySense-Blueprint&color=brightgreen) 

* HandySense คือ ระบบอุปกรณ์ IOT สำหรับเกษตรอัจฉริยะที่สามารถแสดงค่าข้อมูล ปัจจัยในการควบคุมผลผลิตทางการเกษตร โดยใช้เทคโนโลยีเซนเซอร์เข้ามาช่วยในกระบวนการเพาะปลูกซึ่งช่วยให้เกษตรกรสามารถควบคุมสภาวะแวดล้อมในการปลูกได้ตั้งแต่เริ่มต้นส่งผลให้สามารถควบคุมคุณภาพและประเมินปริมาณผลผลิต 
* รวมถึงช่วยเรื่องการเพิ่มคุณค่าของผลผลิตได้โดยใช้การควบคุมกระบวนการเพาะปลูกเพื่อให้ผลผลิตออกในช่วงที่มีความต้องการหรือผลผลิตขาดแคลนรวมถึงการช่วยเกษตรกรนำองค์ความรู้ที่เกิดจากทักษะที่ไม่สามารถถ่ายทอดให้เข้าใจได้เนื่องจากเป็นภูมิปัญญาและเป็นการทำเกษตรกรรมแบบวิถีชาวบ้านโดยการลองผิดลองถูกหรือเป็นองค์ความรู้ที่สืบทอดต่อกัน
 
# สารบัญ
1. องค์ประกอบของบอร์ด HandySense 
2. ไฟล์ PCB และ SCH 
3. BluePrint (GerberFile)
4. รายการอุปกรณ์อิเล็กทรอนิกส์ BOM (bill of material)
5. คู่มือการใช้งาน 

# 1. องค์ประกอบของบอร์ด HandySense 

![hds-logo_0](https://github.com/HandySense/HandySense/blob/main/HSborad.PNG)

โดย HandySense Board ประกอบด้วยอินเตอร์เฟสการสื่อสารหลักเป็น I2C, SPI, Analog, WIFI 
* I2C ต่อ Connector ออกมาให้ใช้งาน 2 ชุด (+5V)  
* Analog ต่อ Connector ออกมาให้ใช้งาน 3 pin ได้แก่ IO36(A0), IO39(A3), IO32(A4)
* SPI ขา CS/SS เป็น IO5 บนบอร์ดไม่ได้ต่ออุปกรณ์ แต่ต่อกับ IDC10 (block 10 pin) 
* ส่วน WIFI สื่อสารข้อมูลกับ Server เป็นหลัก
* Output เป็น Relay 220V AC 10A โดยต่อ pin ได้แก่ IO25, IO4, IO12, IO13 
* รายละเอียดแสดงดังภาพ (*แสดงพอสังเขป โดยลเอียดอ่านคู่มือเพิ่มเติม)

![detailHS](https://github.com/HandySense/HandySense/blob/main/detailHS.PNG)

# 2. ไฟล์ PCB และ SCH 
สำหรับ HandySense version นี้ออกแบบด้วยโปรแกรม Autodesk Eagle ซึ่งไฟล์สามารถกดดาวน์โหลดได้ด้านบน 

* ไฟล์ .brd (PCB  layout) และ .sch
![sch](https://github.com/HandySense/HandySense/blob/main/%E0%B8%9A%E0%B8%AD%E0%B8%A3%E0%B9%8C%E0%B8%94%20HS%20.png)

# 3. BluePrint (Gerber File)
สำหรับ BluePrint จะ save เป็น Gerber File ที่สามารถนำไปสั่งผลิตได้ โดยไม่ต้องปรับแก้อะไร สามารถดาวน์โหลดได้ด้านบน

* Gerber File 
![gerber](https://github.com/HandySense/HandySense/blob/main/gerber.png)

# 4. รายการอุปกรณ์อิเล็กทรอนิกส์ BOM (Bill Of Material)
* สำหรับรายการอุปกรณ์อิเล็กทรอนิกส์ของบอร์ด HandySense มีรายการทั้งหมดอยู่ในไฟล์ ชื่อ HandySense_v1.0.2_BOM.ods (เปิดดูด้วยโปรแกรม MS Excel)
ซึ่งจะบอกรายละเอียดที่จำเป็นและราคาต่อบอร์ดหรือราคารวมคร่าว ๆ ได้ (อาจจะมี +,- เนื่องจากราคามีการอับเดตเป็นช่วง ๆ ขึ้นอยู่กับผู้ขาย) สามารถที่จะระบุจำนวนบอร์ดที่ต้องการได้ในช่อง

* BOM (Bill Of Material)
![bom](https://github.com/HandySense/HandySense/blob/main/bom.PNG)

# 5. คู่มือการใช้งาน 
* สำหรับคู่มือการใช้งาน จะประกอบไปด้วย 2 เล่ม ได้แก่ 
* คู่มือสอนใช้งานบอร์ด HandySense
* คู่มือสอนใช้งาน HandySense Dashboard 

![bom](https://github.com/HandySense/HandySense/blob/main/%E0%B8%84%E0%B8%B9%E0%B9%8B%E0%B8%A1%E0%B8%B7%E0%B8%AD%20HS.png)



# Open Hardware Facts
![](https://github.com/HandySense/HandySense/blob/main/os.PNG)

