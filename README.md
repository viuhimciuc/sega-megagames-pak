# 🎮 Sega Mega Games Pak (6-in-1)

[![KiCad Version](https://img.shields.io/badge/KiCad-v8.0+-blue?logo=kicad&logoColor=white)](https://kicad.org/)
[![Platform](https://img.shields.io/badge/Platform-Sega%20Genesis%20%2F%20Mega%20Drive-black)](https://en.wikipedia.org/wiki/Sega_Genesis)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

An open-source custom menu compilation project for **Sega Genesis / Mega Drive** multi-game cartridges. This repository provides specialized ROM configurations designed to operate seamlessly with the companion hardware platform: [GEN-CART-171-6570A_MultiGames](https://github.com/viuhimciuc/Cartridge-SEGA/tree/main/GEN-CART-171-6570A_MultiGames).

---

## 🛠️ Hardware Compatibility

This software multi-game compilation is built specifically to be flashed and deployed on the custom multi-game retro-hardware board layout:

<p align="center">
  <a href="https://github.com/viuhimciuc/Cartridge-SEGA/tree/main/GEN-CART-171-6570A_MultiGames">
    <img src="https://raw.githubusercontent.com/viuhimciuc/Cartridge-SEGA/main/GEN-CART-171-6570A_MultiGames/Documents/GEN-CART-171-6570A_MultiGames_top.png" alt="GEN-CART-171-6570A MultiGames PCB Layout" width="45%">
  </a>
</p>

---

## 📚 Multi-Game Volumes & Labels

Each volume represents a unique compilation bundle designed for production. Below are the corresponding directory configurations along with their high-quality physical cartridge labels:

<table align="center">
  <tr>
    <td align="center"><b>📂 Volume Folder</b></td>
    <td align="center"><b>🎨 Physical Cartridge Label Artwork</b></td>
  </tr>
  <tr>
    <td><code>megagames-pak-vol1</code></td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/viuhimciuc/Cartridge-Labels/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol1.png" alt="Sega Mega Games Pak Vol 1 Label" width="220px"><br>
      <a href="https://github.com/viuhimciuc/Cartridge-Labels/blob/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol1.png">📄 View Source Label</a>
    </td>
  </tr>
  <tr>
    <td><code>megagames-pak-vol2</code></td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/viuhimciuc/Cartridge-Labels/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol2.png" alt="Sega Mega Games Pak Vol 2 Label" width="220px"><br>
      <a href="https://github.com/viuhimciuc/Cartridge-Labels/blob/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol2.png">📄 View Source Label</a>
    </td>
  </tr>
  <tr>
    <td><code>megagames-pak-vol3</code></td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/viuhimciuc/Cartridge-Labels/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol3.png" alt="Sega Mega Games Pak Vol 3 Label" width="220px"><br>
      <a href="https://github.com/viuhimciuc/Cartridge-Labels/blob/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol3.png">📄 View Source Label</a>
    </td>
  </tr>
  <tr>
    <td><code>megagames-pak-vol4</code></td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/viuhimciuc/Cartridge-Labels/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol4.png" alt="Sega Mega Games Pak Vol 4 Label" width="220px"><br>
      <a href="https://github.com/viuhimciuc/Cartridge-Labels/blob/main/labels-for-sega-genesis/files-in-png-sega-genesis/6_Pack_vol4.png">📄 View Source Label</a>
    </td>
  </tr>
</table>

---

## 🗂️ Repository Structure

```text
├── megagames-pak-vol1/    # Compilation data, menu engine and tools for Volume 1
├── megagames-pak-vol2/    # Compilation data, menu engine and tools for Volume 2
├── megagames-pak-vol3/    # Compilation data, menu engine and tools for Volume 3
├── megagames-pak-vol4/    # Compilation data, menu engine and tools for Volume 4
└── README.md              # Documentation
```

---

## 🚀 How to Use

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/viuhimciuc/sega-megagames-pak.git
   cd sega-megagames-pak
   ```
2. **Build/Flash ROMs:** Follow the custom building utilities or compiler scripts included within each volume directory to generate the fully merged multi-game system ROM file.
3. **Hardware Deployment:** Use an EEPROM/Flash memory programmer (such as MiniPro TL866 or similar tool compatible with your target chip) to burn the generated binary onto your flash memory chip mounted to the [GEN-CART-171-6570A_MultiGames PCB](https://github.com/viuhimciuc/Cartridge-SEGA/tree/main/GEN-CART-171-6570A_MultiGames).

---

## 🤝 Related Projects
* **Hardware Schematic & PCBs:** [Cartridge-SEGA Repository](https://github.com/viuhimciuc/Cartridge-SEGA) 🛠️
* **High-Res Shell Graphic Labels:** [Cartridge-Labels Assets Collection](https://github.com/viuhimciuc/Cartridge-Labels) 🎨
