<!-- Please do not change this logo with link -->

[![MCHP](./images/microchip.png)](https://www.microchip.com)

# How to Program an MPLAB® X IDE Project for AVR® DD

This page demonstrates how to use the MPLAB® X IDE to program an AVR® device with an C-Nano-Out-of-the-Box.X. This can be applied for any other projects.

## Operation

1.  Connect the board to the PC.

2.  Open the C-Nano-Out-of-the-Box.X project in MPLAB® X IDE.

3.  Set the C-Nano-Out-of-the-Box.X project as main project. Right click on the project in the **Projects** tab and select **Set as Main Project**.

<br><img src="./images/Program_Set_as_Main_Project.PNG" height="500">

4.  Clean and build the C-Nano-Out-of-the-Box.X project. Right click on the **C-Nano-Out-of-the-Box.X** project and select **Clean and Build**.

<br><img src="./images/Program_Clean_and_Build.png" height="500">

5.  Select the **AVR64DD32 Curiosity Nano** in the Connected Hardware Tool section of the project settings:

- Right click on the project and click **Properties**
- Click on the arrow below the Connected Hardware Tool
- Select the **AVR64DD32 Curiosity Nano** (click on the **SN**), click **Apply** and then click **OK**

<br><img src="./images/Program_Tool_Selection.png" height="400">

6.  Program the project to the board. Right click on the project and select **Make and Program Device**.

<br><img src="./images/Program_Make_and_Program_Device.png" height="500">

## Summary

These are all the steps needed to program an C-Nano-Out-of-the-Box.X project in MPLAB® X IDE.
