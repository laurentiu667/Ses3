/*
 * ATTENTION: The "eval" devtool has been used (maybe by default in mode: "development").
 * This devtool is neither made for production nor for readable output files.
 * It uses "eval()" calls to create a separate source file in the browser devtools.
 * If you are trying to read the output file, select a different devtool (https://webpack.js.org/configuration/devtool/)
 * or disable the default devtool with "devtool: false".
 * If you are looking for production-ready output files, see mode: "production" (https://webpack.js.org/configuration/mode/).
 */
/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	var __webpack_modules__ = ({

/***/ "./js/animation.js":
/*!*************************!*\
  !*** ./js/animation.js ***!
  \*************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

eval("__webpack_require__.r(__webpack_exports__);\n/* harmony export */ __webpack_require__.d(__webpack_exports__, {\n/* harmony export */   posX: () => (/* binding */ posX),\n/* harmony export */   posY: () => (/* binding */ posY)\n/* harmony export */ });\n/* harmony import */ var _sprites_Monster_js__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./sprites/Monster.js */ \"./js/sprites/Monster.js\");\n\r\nconst MONSTER_COUNT = 10;\r\n\r\nlet spriteList = new Array();\r\n\r\n// N'oubliez pas que posX et posY ne seront pas visible dans la classe Monster, vous\r\n// aurez donc à passer ces positions en paramètre de la fonction tick du monstre, ou à les exporter\r\nlet posX = 500;\r\nlet posY = 350;\r\n\r\nwindow.addEventListener(\"load\", () => {\r\n\tfor (let i = 0; i < MONSTER_COUNT; i++) {\r\n\t\tspriteList.push(new _sprites_Monster_js__WEBPACK_IMPORTED_MODULE_0__[\"default\"]());\r\n\t}\r\n\r\n\tdocument.querySelector(\"main\").onmousemove = event => {\r\n\t\tposX = event.x;\r\n\t\tposY = event.y;\r\n\t}\r\n\r\n\ttick();\r\n});\r\n\r\nconst tick = () => {\r\n\tfor (let i = 0; i < spriteList.length; i++) {\r\n\t\tlet alive = spriteList[i].tick();\r\n\r\n\t\tif (!alive) {\r\n\t\t\tspriteList.splice(i, 1);\r\n\t\t\ti--;\r\n\t\t}\r\n\t}\r\n\r\n\twindow.requestAnimationFrame(tick);\r\n}\n\n//# sourceURL=webpack://exercice/./js/animation.js?");

/***/ }),

/***/ "./js/sprites/Monster.js":
/*!*******************************!*\
  !*** ./js/sprites/Monster.js ***!
  \*******************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

eval("__webpack_require__.r(__webpack_exports__);\n/* harmony export */ __webpack_require__.d(__webpack_exports__, {\n/* harmony export */   \"default\": () => (/* binding */ Monster)\n/* harmony export */ });\n/* harmony import */ var _animation_js__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ../animation.js */ \"./js/animation.js\");\n/* harmony import */ var _utils_js__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../utils.js */ \"./js/utils.js\");\n\r\n\r\n\r\nclass Monster {\r\n\tconstructor () {\r\n\t\tthis.node = document.createElement(\"div\");\r\n\t\tthis.node.className = \"monster\";\r\n\t\tdocument.querySelector(\"main\").appendChild(this.node);\r\n\r\n\t\tthis.velocityX = 0;\r\n\t\tthis.velocityY = 0;\r\n\t\tthis.velocityFactor = 0.2;\r\n\t\tthis.currentPosX = 800 - Math.random() * 1600;\r\n\t\tthis.currentPosY = 800 - Math.random() * 1600;\r\n\t\tthis.maxVelocityX = 8;\r\n\t\tthis.maxVelocityY = 8;\r\n\t}\r\n\r\n\ttick() {\r\n\t\tif (this.currentPosX < _animation_js__WEBPACK_IMPORTED_MODULE_0__.posX) {\r\n\t\t\tif (this.velocityX < this.maxVelocityX) {\r\n\t\t\t\tthis.velocityX += this.velocityFactor;\r\n\t\t\t}\r\n\t\t}\r\n\t\telse if (this.currentPosX > _animation_js__WEBPACK_IMPORTED_MODULE_0__.posX) {\r\n\t\t\tif (this.velocityX > -this.maxVelocityX) {\r\n\t\t\t\tthis.velocityX -= this.velocityFactor;\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tif (this.currentPosY < _animation_js__WEBPACK_IMPORTED_MODULE_0__.posY) {\r\n\t\t\tif (this.velocityY < this.maxVelocityY) {\r\n\t\t\t\tthis.velocityY += this.velocityFactor;\r\n\t\t\t}\r\n\t\t}\r\n\t\telse if (this.currentPosY > _animation_js__WEBPACK_IMPORTED_MODULE_0__.posY) {\r\n\t\t\tif (this.velocityY > -this.maxVelocityY) {\r\n\t\t\t\tthis.velocityY -= this.velocityFactor;\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tthis.currentPosX += this.velocityX;\r\n\t\tthis.currentPosY += this.velocityY;\r\n\r\n\t\tthis.node.style.left = this.currentPosX + \"px\";\r\n\t\tthis.node.style.top = this.currentPosY + \"px\";\r\n\r\n\t\tlet angle = (0,_utils_js__WEBPACK_IMPORTED_MODULE_1__.getElementAngle)(this.currentPosX, this.currentPosY, _animation_js__WEBPACK_IMPORTED_MODULE_0__.posX, _animation_js__WEBPACK_IMPORTED_MODULE_0__.posY);\r\n\t\t(0,_utils_js__WEBPACK_IMPORTED_MODULE_1__.rotateElement)(this.node, angle);\r\n\r\n\t\treturn true;\r\n\t}\r\n}\n\n//# sourceURL=webpack://exercice/./js/sprites/Monster.js?");

/***/ }),

/***/ "./js/utils.js":
/*!*********************!*\
  !*** ./js/utils.js ***!
  \*********************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

eval("__webpack_require__.r(__webpack_exports__);\n/* harmony export */ __webpack_require__.d(__webpack_exports__, {\n/* harmony export */   getElementAngle: () => (/* binding */ getElementAngle),\n/* harmony export */   rotateElement: () => (/* binding */ rotateElement)\n/* harmony export */ });\n\r\n// Permet de faire une rotation d'un élément pour un angle donné.\r\n// Exemple : rotateElement(document.getElementById(\"elem\"), 45).\r\n//\t\t\t Prend le DIV#elem dans son angle original (0) et fait une\r\n//\t\t\t rotation de 45 degré.\r\nconst rotateElement = (node, angle) => {\r\n    let properties = ['transform'];\r\n    let p = null;\r\n    let result = null;\r\n    \r\n    while (p = properties.shift()) {\r\n        if (typeof node.style[p] != 'undefined') {\r\n            result = p;\r\n        }\r\n    }\r\n    \r\n    if (result != null) {\r\n    \tnode.style[result] = 'rotate(' + angle + 'deg)';\r\n\t}\r\n}\r\n\r\n// L'angle 0 correspond au nord (vers le haut)\r\n// Exemple : getElementAngle(posElementX, posElementY, posSourisX, posSourisY)\r\n//\t\t\t Ceci retournera l'angle de l'élément par rapport à la position de la souris\r\nconst getElementAngle = (x1, y1, x2, y2) => {\r\n\tlet adj = x2 - x1;\r\n\tlet opp = y2 - y1;\r\n\t\r\n\tlet angle = Math.abs(Math.atan(opp/adj) * 180/Math.PI);\r\n\t\r\n\tif (adj > 0 && opp < 0 ) {\r\n\t\tangle = 90 - angle;\r\n\t}\r\n\telse if (adj >= 0 && opp >= 0) {\r\n\t\tangle += 90;\r\n\t}\r\n\telse if (adj < 0 && opp >= 0) {\r\n\t\tangle = 180 + (90 - angle);\r\n\t}\r\n\telse {\r\n\t\tangle += 270;\r\n\t}\r\n\t\r\n\treturn angle;\r\n}\n\n//# sourceURL=webpack://exercice/./js/utils.js?");

/***/ })

/******/ 	});
/************************************************************************/
/******/ 	// The module cache
/******/ 	var __webpack_module_cache__ = {};
/******/ 	
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/ 		// Check if module is in cache
/******/ 		var cachedModule = __webpack_module_cache__[moduleId];
/******/ 		if (cachedModule !== undefined) {
/******/ 			return cachedModule.exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = __webpack_module_cache__[moduleId] = {
/******/ 			// no module.id needed
/******/ 			// no module.loaded needed
/******/ 			exports: {}
/******/ 		};
/******/ 	
/******/ 		// Execute the module function
/******/ 		__webpack_modules__[moduleId](module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
/******/ 	/* webpack/runtime/define property getters */
/******/ 	(() => {
/******/ 		// define getter functions for harmony exports
/******/ 		__webpack_require__.d = (exports, definition) => {
/******/ 			for(var key in definition) {
/******/ 				if(__webpack_require__.o(definition, key) && !__webpack_require__.o(exports, key)) {
/******/ 					Object.defineProperty(exports, key, { enumerable: true, get: definition[key] });
/******/ 				}
/******/ 			}
/******/ 		};
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/hasOwnProperty shorthand */
/******/ 	(() => {
/******/ 		__webpack_require__.o = (obj, prop) => (Object.prototype.hasOwnProperty.call(obj, prop))
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/make namespace object */
/******/ 	(() => {
/******/ 		// define __esModule on exports
/******/ 		__webpack_require__.r = (exports) => {
/******/ 			if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 				Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 			}
/******/ 			Object.defineProperty(exports, '__esModule', { value: true });
/******/ 		};
/******/ 	})();
/******/ 	
/************************************************************************/
/******/ 	
/******/ 	// startup
/******/ 	// Load entry module and return exports
/******/ 	// This entry module is referenced by other modules so it can't be inlined
/******/ 	var __webpack_exports__ = __webpack_require__("./js/animation.js");
/******/ 	
/******/ })()
;