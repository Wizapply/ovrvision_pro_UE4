# OvrvisionProSDK for UE4
==================

These are plug-in and the source codes for using Ovrvision by UE4.
However it has some problems. 
Please avoid the adoption to your project that it is under development.

How to build
=================

Build 64bit ovrvision.dll. See https://github.com/Wizapply/OvrvisionPro/tree/develop  
git clone https://github.com/Wizapply/ovrvision_pro_UE4  
(If use develop branch "git checkout -b develop origin/develop")  
Put "ovrvision_pro_UE4/Plugins/OvrvisionPlugin/ovrvision.dll" and "ovrvision_pro_UE4/Binaries/Win64/ovrvision.dll"  
Right click ovrvision_pro_UE4/OvrvisionUE.uproject  
Select "Generate Visual Studio project files"  
Run ovrvision_pro_UE4/OvrvisionUE.sln  
Open dev_map.umap  
Play > VR preview  

How to use
==================

1. This was latest tested on 4.10.4

2. Copy the plugins folder to your `<Game>/Plugins/` folder; alternatively, you can copy to the `Engine/Plugins/` if you wish to make the plugin available to all of your projects.
   > Do not forget to run UE4's `Generate Project Files` to account for these changes!

Version
==================
2016-3-19 : TEST VERSION
