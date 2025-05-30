# Asset Naming Prefix

Supported Version: Unreal 5.4 

*Support for other unreal engine 5 versions coming soon*
*Please use this tool at your own risk. Everything has been tested as much as possible but the author cannot be held resposible for any lose data if a crash occurs*

**Asset Naming Prefix** is an editor plugin for Unreal Engine 5 that automatically enforces your team’s asset‐naming conventions. You define a DataTable mapping each asset class (e.g. `Material`, `Blueprint`) to a prefix (e.g. `M_`, `BP_`), and new assets are renamed on creation. You can also run it manually on existing assets or entire folders via the Content Browser context menu.

Overview and installation Guide: https://youtube.com/playlist?list=PLpjKlZ2EDiUPQ_TrEhypYRPTDBQwbzUnc&si=O6DH3ZHqOH1gFt3k

## Features

- ⚙️ **Auto-Prefixing**: As soon as you create a new asset under your configured paths, it’s renamed to `<Prefix><AssetName>`.  
- 📋 **Manual Run**: Right-click any asset or folder to “Apply Asset Naming Prefix” on demand.  
- 🔧 **Configurable**:  
  - Toggle auto-prefix on/off  
  - Define which root paths to watch (or “allow all”)  
  - Control maximum renames per tick and tick interval for performance  
  - Enable or disable log output  
  - Reference only DataTables of your custom `FAssetPrefixRow` struct  

## Installation

1. **Download**  
   - Download plugin as zip from the green < code > button
2. **Copy**  
   - Drop the `AssetNamingPrefix` folder into your project's `Plugins/` directory.
3. **Enable**  
   - Launch the Editor, go to **Edit → Plugins**, find **Asset Naming Prefix**, and tick **Enabled**.  
   - Restart the Editor when prompted.

## Configuration

1. Open **Edit → Project Settings → Plugins → Asset Naming Prefix**.  
2. Assign your **Prefix Table** (a DataTable of `FAssetPrefixRow`).
3. You can find the pre-made and configured prefix table under `Plugins/AssetNamingPrefix/Content/DT_AssetNamingPrefixList.uasset`
4. Adjust:  
   - **Enable Auto-Prefixing**  
   - **Allow All Paths** or specify root directories  
   - **Max Renames Per Tick** & **Tick Interval**  
   - **Output to Log**  
   - **Remove Old Prefix** toggle  

## Usage

- **Auto**: Create any new asset under `/Game` (or your defined paths) and watch it rename instantly.  
- **Manual**: In the Content Browser, right-click assets or folders and select **Apply Asset Naming Prefix**.

*© 2025 Josh Davidson*  

