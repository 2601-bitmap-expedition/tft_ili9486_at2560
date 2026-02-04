# commands
## initialize
|Command|Parameters|Description|
|---|---|---|
|`0x01`||Soft reset. (resets commands and parameters to their default values)|
|`0x11`||Sleep out|
|`0x3A`|`0x55`|Set pixel format to RGB565. (16bit)|
|`0x36`|`0x48`|Memory access control. (Column Address Order = 1, RGB-BGR Order = 1)|
|`0x29`||Display on.|

# references
- ILI9486 - a-Si TFT LCD Single Chip Driver
- ATmega640/1280/1281/2560/2561
