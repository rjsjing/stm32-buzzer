# CLAUDE.md — STM32F103C8T6 蜂鸣器

## 技术栈

- **MCU**: STM32F103C8T6（Cortex-M3, 64KB Flash, 20KB SRAM, 72MHz）
- **库**: ST 标准外设库 v3.5.0
- **构建工具**: Keil MDK uVision5 + EIDE (VSCode 插件 `cl.eide`)
- **调试器**: ST-Link (SWD)

## 目录结构

```
├── Start/           CMSIS 启动 + system_stm32f10x
├── Library/         ST 标准外设库 v3.5.0
├── System/          Delay.c/h — SysTick 延时
├── User/            main.c, stm32f10x_conf.h, stm32f10x_it.c/h
├── build/           EIDE 构建输出
├── Objects/         Keil 编译产物
└── Listings/        编译清单 (.map)
```

## 硬件引脚映射

| 引脚 | 功能 | 连接目标 |
|------|------|----------|
| PB12 | GPIO Out PP | 蜂鸣器 (低电平触发) |

## 功能说明

GPIO 输出控制有源蜂鸣器。PB12 推挽输出，低电平触发蜂鸣器持续鸣响。

## 编码规范

- GPIO 引脚用标准库定义，禁止魔法数字
- 编码: UTF-8，注释用中文

## Git 规范

```
main              ← 稳定分支
提交: feat:/fix:/docs: 格式
```

## 构建命令

```
Keil:  打开 Project.uvprojx → F7 编译 → F8 烧录
EIDE:  Ctrl+Shift+P → "EIDE: Build"
清理:  keilkill.bat
```

## 注意事项

- `USE_STDPERIPH_DRIVER` 和 `STM32F10X_MD` 编译选项必须定义
- 启动文件 `startup_stm32f10x_md.s`
