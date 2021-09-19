
<p align="center">
 <h2 align="center">Simple Library for C++</h2>
 <h4 align="center">A Compact, Simple and Light Library to use on Existing Projects and new Projects</h4>
 <p align="center"></p>
</p>

<p align="center">
 
 <a href="https://en.wikipedia.org/wiki/C%2B%2B">
      <img src="https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=for-the-badge&logo=appveyor"/>
    </a>
    <a href="https://en.wikipedia.org/wiki/Microsoft_Windows">
      <img src="https://img.shields.io/badge/platform-Windows-0078d7.svg?style=for-the-badge&logo=appveyor"/>
    </a>
 
 <a href="https://en.wikipedia.org/wiki/Cheating_in_online_games">
      <img src="https://img.shields.io/badge/arch-x86-red.svg?style=for-the-badge&logo=appveyor"/>
    </a>
 
 <a href="https://en.wikipedia.org/wiki/Cheating_in_online_games">
      <img src="https://img.shields.io/badge/License-MIT-e49eff?style=for-the-badge&logo=appveyor"/>
    </a>
 
 
    
  </p>



## Interfaces
*   **Network Interface** - Allows for Simple HTTPS Connections
*   **Security Interface** - Allows for Hashing of Strings and Hardware Identification
*   **Math Interface** - Fast Time Complexity Mathematics Interface
*   **Utility Interface** - Allows for Miscellaneous functions, Utility functions and Convertions
*   **Memory Interface** - Allows for Fast and Simple Memory Management


---


<a name="-1"></a>

|Documentation|
|--------|
|[Network](#0)|
|[Security](#1)|
|[Math](#2)|
|[Utility](#3)|
|[Memory](#4)|

---
## <a name="0"></a>Network Interface

---

## Get

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| URL | std::string | The Link of the Request |

**Syntax** 

```cpp
std::string Link = "https://github.com/SadKwitty/KwittyLib/raw/main/README.md";
std::string Result = interfaces.Network->Get(Link);
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Headers | std::string | The Header from the Requested Link |


  [Back to Interfaces](#-1)


---

## <a name="1"></a>Security Interface

---

## CHash

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Text | std::string | The String to Hash |

**Syntax** 

```cpp
std::string Hash = interfaces.Security->CHash("Hello World!");
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Hash | std::string | The Hashed String |




## GetPhysicalHWID


**Syntax** 

```cpp
std::string HWID = interfaces.Security->GetPhysicalHWID();
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| HWID | std::string | Hardware ID Based on Storage Drive |




## GetWindowsUID


[ DOES NOT WORK ON ALL WINDOWS VERSIONS ]


**Syntax** 

```cpp
std::string UID = interfaces.Security->GetWindowsUID();
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| UID | std::string | Windows GUID |



    



---

## <a name="2"></a>Math Interface

---

## AccurateSQRT

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Square | int | The number to Get the Square root Off |

**Syntax** 

```cpp
int Root = interfaces.Math->AccurateSQRT(25);
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Root | int | Square root of Input |


## DefaultSQRT

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Square | int | The number to Get the Square root Off |

**Syntax** 

```cpp
int Root = interfaces.Math->DefaultSQRT(25);
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Root | int | Square root of Input |


## DefaultSQRT

[ Second Iteration ]

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Square | int | The number to Get the Square root Off |
| Output | int | The output of the Function |

**Syntax** 

```cpp
int Root = 0;
interfaces.Math->DefaultSQRT(25, Root);
```




## FastSQRT

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Square | int | The number to Get the Square root Off |

**Syntax** 

```cpp
int Root = interfaces.Math->FastSQRT(25);
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Root | int | Square root of Input |

## SQRT

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Square | int | The number to Get the Square root Off |

**Syntax** 

```cpp
int Root = interfaces.Math->SQRT(25);
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Root | int | Square root of Input |

## Power

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Number | int | The Number to get the Power off |
| Number | int | The Power |

**Syntax** 

```cpp
int PowerOf5 = interfaces.Math->Power(5, 2);
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Power | int | The Power Of the Original Number |


  [Back to Interfaces](#-1)

---


## <a name="3"></a>Utility Interface

---

## ConvertToBinary

**Parameters**

| Name | Type | Description |
| :--- | :--- | :--- |
| Text | std::string | The Text to be Converted to Binary |

**Syntax** 

```cpp
auto ByteArray = interfaces.Utils->ConvertToBinary("Hello!");
```

**Returns**

| Name | Type | Description |
| :--- | :--- | :--- |
| Bytes | std::vector<unsigned long> | Binary Bits |
 
 
 
 



---




### Future Plans

  *   **Network Interface** - Improve Network Speed
  *   **Network Interface** - Asynchronous Connections
  *   **Network Interface** - Multithreading
  *   **Network Interface** - Tcp Socket System
  *   **Security Interface** - Debug Detection
  *   **Security Interface** - Virtual Machine Detection
  *   **Security Interface** - DLL Injection Protection
  *   **Security Interface** - DLL Filter
  *   **Security Interface** - Memory Integrity Check
  *   **Security Interface** - File Integrity Check
  *   **Security Interface** - Virtualization
  *   **Kernel Interface** - Adding Kernel Interface
  *   **Kernel Interface** - Loading Drivers from Usermode
  *   **Kernel Interface** - Disabling Driver Signature Enforment
  *   **Utility Interface** - Adding more Convertions
  *   **Math Interface** - Adding more Math Functions and Algorithms




