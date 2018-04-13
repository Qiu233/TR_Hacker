# TR_Hacker
![](Pictures/Icon.png)
------

## 简述
TR_Hacker，正式名称为Terraria Hacker，用于对游戏Terraria进行内存修改。
功能上可以说非常Strong了。


## 环境要求(你能在Release压缩包中的说明书内找到，部分修改):

修改器使用环境：
>CPU：最好是Intel Core系列的，除了Intel和AMD的CPU，几乎完全不支持  
操作系统：Windows 7及以上，64位  
.Net：4.6.2，不要安装多个版本的.Net!   
Terraria：1.3.5.3  

## 特色:
包括但不限于:
>可视化物品修改  
强大的脚本  
背包的保存与恢复  
传送玩家以及查看玩家背包  
多种骚操作，例如燃烧友好NPC等等  

从类型来说，THK支持30~40项修改，而从数量上来说，支持上百种修改。
有一些功能是需要特地说一说的：

* 可以直接添加物品到背包，这意味着不再需要修改已有物品类型再重新拾取或者重新进入而获得正确的物品。
* 直接初始化物品属性，在界面输入物品类型，数量，前缀然后点击初始化，即可在选定位置获得一个属性完整的物品。
* 保存背包可直接将当前背包信息保存到一个文件(.inv)，包括装备、饰品、燃料等。
* 加载背包可直接把上一步或者从其他途径得到的背包文件(.inv)加载到当前背包。
* 支持插件(代替了说明书中提到的脚本)，修改器在HackFunctions类中提供了很多函数用于修改，使用C#为修改器编写插件可以调用这些函数。值得一提的是，修改器实际上提供了几乎所有的物品属性修改接口，但是界面上空间不足，所以只提供了重要的属性修改，编写插件可以调用这些接口，实现修改器原本没有的功能。
* 插件的说明书可在Release压缩包中找到，同时还有一份插件的样例，样例提供了几个简单的功能。

## 工程结构:
构建时产生的二进制文件会被输出到./Debug和./Release文件夹
>TR_Hacker_DLL:修改器的修改逻辑实现  
Language:	C  
IDE:		Code::Blocks  
Terraria_Hacker:修改器的界面逻辑  
Language:	C#  
IDE:		SharpDevelop/VS  
TR_DATA:没有用的东西，曾用来查看一些简单的数据  
Language:	C#  
IDE:		SharpDevelop/VS  
RegisterInfo:已经弃用，曾用于生成注册信息  
Language:	C#  
IDE:		SharpDevelop/VS  
Register:已经弃用，曾用于根据注册信息生成注册码  
Language:	C  
IDE:		Code::Blocks  
Hacker_Test:已经弃用，曾用于检查修改器无法使用的原因  
Language:	C  
IDE:		Code::Blocks  
Image_Packer:用于打包图片文件  
Language:	C#  
IDE:		SharpDevelop/VS  
MyCheatLibrary:改造过的CheatLibrary，负责一些比较高级的工作  
Language:	C++  
IDE:		VS  
TR_DDOS:用于攻击Terraria服务器，大部分代码来自Terraria  
Language:	C#  
IDE:		SharpDevelop/VS  

## 关于开源:
开源服从协议 GPL V3。
