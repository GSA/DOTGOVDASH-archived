(function () {
  var callWithJQuery,
    extend = function (child, parent) { for (var key in parent) { if (hasProp.call(parent, key)) child[key] = parent[key]; } function ctor() { this.constructor = child; } ctor.prototype = parent.prototype; child.prototype = new ctor(); child.__super__ = parent.prototype; return child; },
    hasProp = {}.hasOwnProperty,
    slice = [].slice;

  var rowsPerPage = 1000;
  var curPage = 1;
  var globalSearchValue = "";
  var globalSearchKey = "";
  var globalFilterValue = "";
  var globalFilterKey = "";
  var sortInfo = {
    colIndex: -1,
    colKey: '',
    direction: 0
    // 0: NORMAL
    // -1: DESC
    // 1: ASC
  }


  callWithJQuery = function (pivotModule) {
    if (typeof exports === "object" && typeof module === "object") {
      return pivotModule(require("jquery"));
    } else if (typeof define === "function" && define.amd) {
      return define(["jquery"], pivotModule);
    } else {
      return pivotModule(jQuery);
    }
  };

  callWithJQuery(function ($) {
    var CustomPivotData, SubtotalRenderer, aggregatorTemplates, subtotalAggregatorTemplates, usFmtPct;
    CustomPivotData = (function (superClass) {
      var processKey;

      extend(CustomPivotData, superClass);

      function CustomPivotData(input, opts) {
        CustomPivotData.__super__.constructor.call(this, input, opts);
      }

      processKey = function (record, totals, keys, attrs, getAggregator) {
        var addKey, attr, flatKey, k, key, len, ref;
        key = [];
        addKey = false;
        for (k = 0, len = attrs.length; k < len; k++) {
          attr = attrs[k];
          key.push((ref = record[attr]) != null ? ref : "null");
          flatKey = key.join(String.fromCharCode(0));
          if (!totals[flatKey]) {
            totals[flatKey] = getAggregator(key.slice());
            addKey = true;
          }
          totals[flatKey].push(record);
        }
        if (addKey) {
          keys.push(key);
        }
        return key;
      };

      CustomPivotData.prototype.processRecord = function (record) {

        var colKey, fColKey, fRowKey, flatColKey, flatRowKey, i, j, k, m, n, ref, results, rowKey;
        rowKey = [];
        colKey = [];
        this.allTotal.push(record);
        rowKey = processKey(record, this.rowTotals, this.rowKeys, this.rowAttrs, (function (_this) {
          return function (key) {
            return _this.aggregator(_this, key, []);
          };
        })(this));
        colKey = processKey(record, this.colTotals, this.colKeys, this.colAttrs, (function (_this) {
          return function (key) {
            return _this.aggregator(_this, [], key);
          };
        })(this));

        m = rowKey.length - 1;
        n = colKey.length - 1;
        if (m < 0 || n < 0) {
          return;
        }
        results = [];
        for (i = k = 0, ref = m; 0 <= ref ? k <= ref : k >= ref; i = 0 <= ref ? ++k : --k) {
          fRowKey = rowKey.slice(0, i + 1);
          flatRowKey = fRowKey.join(String.fromCharCode(0));
          if (!this.tree[flatRowKey]) {
            this.tree[flatRowKey] = {};
          }
          results.push((function () {
            var l, ref1, results1;
            results1 = [];
            for (j = l = 0, ref1 = n; 0 <= ref1 ? l <= ref1 : l >= ref1; j = 0 <= ref1 ? ++l : --l) {
              fColKey = colKey.slice(0, j + 1);
              flatColKey = fColKey.join(String.fromCharCode(0));

              if (!this.tree[flatRowKey][flatColKey]) {
                this.tree[flatRowKey][flatColKey] = this.aggregator(this, fRowKey, fColKey);
              }
              results1.push(this.tree[flatRowKey][flatColKey].push(record));
            }
            return results1;
          }).call(this));
        }


        //global search logic
        const value = this.tree[flatRowKey][flatColKey].value();

        if (this._rowKeys == undefined) {
          this._rowKeys = {};
        }

        if (this._colKeys == undefined) {
          this._colKeys = {};
        }

        if (globalSearchValue != "") {
          if (value == globalSearchValue && !this._rowKeys[flatRowKey]) {
            this._rowKeys[flatRowKey] = rowKey;
          }
        }

        if (globalSearchKey != "" && flatColKey.toLowerCase().indexOf(globalSearchKey) != -1 && !this._colKeys[flatColKey]) {
            this._colKeys[flatColKey] = colKey;
        }

        if (globalSearchKey != "" && flatRowKey.toLowerCase().indexOf(globalSearchKey) != -1 && !this._rowKeys[flatRowKey]) {
            this._rowKeys[flatRowKey] = rowKey;
        }


        if (globalFilterKey != "" && flatColKey.toLowerCase().indexOf(globalFilterKey) != -1 && !this._colKeys[flatColKey]) {
          this._colKeys[flatColKey] = colKey;
        }

        if (globalFilterKey != "" && flatRowKey.toLowerCase().indexOf(globalFilterKey) != -1 && !this._rowKeys[flatRowKey]) {
            this._rowKeys[flatRowKey] = rowKey;
        }

        //for last record update rowKeys and colKeys
        if (this.input[this.input.length - 1] === record) {
          if (globalSearchKey != "") {
            rowLen = Object.keys(this._rowKeys).length;
            colLen = Object.keys(this._colKeys).length;
            if (rowLen == 0 && colLen == 0) {
              this.rowKeys = [];
              this.colKey = [];
            } else {
              if (rowLen) {
                this.rowKeys = Object.values(this._rowKeys);
              }
              if (colLen) {
                this.colKeys = Object.values(this._colKeys);
              }
            }
          }else if(globalSearchValue != ""){
            this.rowKeys = Object.values(this._rowKeys);
          }

          if (globalFilterKey != "") {
            rowLen = Object.keys(this._rowKeys).length;
            colLen = Object.keys(this._colKeys).length;
            if (rowLen == 0 && colLen == 0) {
              this.rowKeys = [];
              this.colKey = [];
            } else {
              if (rowLen) {
                this.rowKeys = Object.values(this._rowKeys);
              }
              if (colLen) {
                this.colKeys = Object.values(this._colKeys);
              }
            }
          }else if(globalFilterKey != ""){
            this.rowKeys = Object.values(this._rowKeys);
          }


          //column sort logic
          // if (sortInfo.colIndex >= 0 && sortInfo.direction != 0) {
          //   var f = [], d, a = sortInfo.direction, c = sortInfo.colIndex;
          //   b = this;
          //   b.sorted = !1;
          //   var h = b.getRowKeys()
          //     , e = b.getColKeys();
          //   if (sortInfo.colKey !== JSON.stringify(e[c])) {
          //     sortInfo.colIndex = -1;
          //     sortInfo.direction = 0;
          //     sortInfo.colKey = null;
          //   } else {
          //     for (d in h) {
          //       var p = h[d];
          //       var n = null != c ? e[c] : [];
          //       n = b.getAggregator(p, n);
          //       f.push({
          //         val: n.value(),
          //         key: p
          //       })
          //     }
          //     f.sort(function (b, c) {
          //       return a * $.pivotUtilities.naturalSort(b.val, c.val)
          //     });
          //     b.rowKeys = [];
          //     for (d = 0; d < f.length; d++)
          //       b.rowKeys.push(f[d].key);
          //     b.sorted = !0
          //   }
          // }
        }

        return results;
      };

      return CustomPivotData;

    })($.pivotUtilities.PivotData);

    $.pivotUtilities.CustomPivotData = CustomPivotData;


    SubtotalRenderer = function (pivotData, opts) {
      var setTextContent, addClass, adjustAxisHeader, allTotal, arrowCollapsed, arrowExpanded, buildAxisHeader, buildColAxisHeaders, buildColHeader, buildColTotals, buildColTotalsHeader, buildGrandTotal, buildRowAxisHeaders, buildRowHeader, buildRowTotalsHeader, buildValues, classColCollapsed, classColExpanded, classColHide, classColShow, classCollapsed, classExpanded, classRowCollapsed, classRowExpanded, classRowHide, classRowShow, clickStatusCollapsed, clickStatusExpanded, colAttrs, colKeys, colTotals, collapseAxis, collapseAxisHeaders, collapseChildCol, collapseChildRow, collapseCol, collapseHiddenColSubtotal, collapseRow, collapseShowColSubtotal, collapseShowRowSubtotal, createElement, defaults, expandAxis, expandChildCol, expandChildRow, expandCol, expandHideColSubtotal, expandHideRowSubtotal, expandRow, expandShowColSubtotal, expandShowRowSubtotal, getHeaderText, getTableEventHandlers, hasClass, hideChildCol, hideChildRow, main, processKeys, removeClass, replaceClass, rowAttrs, rowKeys, rowTotals, setAttributes, showChildCol, showChildRow, tree;
      defaults = {
        table: {
          clickCallback: null
        },
        localeStrings: {
          totals: "Totals",
          subtotalOf: "Subtotal of"
        },
        arrowCollapsed: "\u25B6",
        arrowExpanded: "\u25E2",
        rowSubtotalDisplay: {
          displayOnTop: true,
          disableFrom: 99999,
          collapseAt: 99999,
          hideOnExpand: false,
          disableExpandCollapse: false
        },
        colSubtotalDisplay: {
          displayOnTop: true,
          disableFrom: 99999,
          collapseAt: 99999,
          hideOnExpand: false,
          disableExpandCollapse: false
        }
      };
      opts = $.extend(true, {}, defaults, opts);
      if (opts.rowSubtotalDisplay.disableSubtotal) {
        opts.rowSubtotalDisplay.disableFrom = 0;
      }
      if (typeof opts.rowSubtotalDisplay.disableAfter !== 'undefined' && opts.rowSubtotalDisplay.disableAfter !== null) {
        opts.rowSubtotalDisplay.disableFrom = opts.rowSubtotalDisplay.disableAfter + 1;
      }
      if (typeof opts.rowSubtotalDisplay.collapseAt !== 'undefined' && opts.collapseRowsAt !== null) {
        opts.rowSubtotalDisplay.collapseAt = opts.collapseRowsAt;
      }
      if (opts.colSubtotalDisplay.disableSubtotal) {
        opts.colSubtotalDisplay.disableFrom = 0;
      }
      if (typeof opts.colSubtotalDisplay.disableAfter !== 'undefined' && opts.colSubtotalDisplay.disableAfter !== null) {
        opts.colSubtotalDisplay.disableFrom = opts.colSubtotalDisplay.disableAfter + 1;
      }
      if (typeof opts.colSubtotalDisplay.collapseAt !== 'undefined' && opts.collapseColsAt !== null) {
        opts.colSubtotalDisplay.collapseAt = opts.collapseColsAt;
      }
      colAttrs = pivotData.colAttrs;
      rowAttrs = pivotData.rowAttrs;
      rowKeys = pivotData.getRowKeys();
      if (rowKeys.length <= (curPage - 1) * rowsPerPage) {
        curPage = 1;
      }
      rowKeys = rowKeys.slice((curPage - 1) * rowsPerPage, curPage * rowsPerPage);
      colKeys = pivotData.getColKeys();
      tree = pivotData.tree;
      rowTotals = pivotData.rowTotals;
      colTotals = pivotData.colTotals;
      allTotal = pivotData.allTotal;
      classRowHide = "rowhide";
      classRowShow = "rowshow";
      classColHide = "colhide";
      classColShow = "colshow";
      clickStatusExpanded = "expanded";
      clickStatusCollapsed = "collapsed";
      classExpanded = "expanded";
      classCollapsed = "collapsed";
      classRowExpanded = "rowexpanded";
      classRowCollapsed = "rowcollapsed";
      classColExpanded = "colexpanded";
      classColCollapsed = "colcollapsed";
      arrowExpanded = opts.arrowExpanded;
      arrowCollapsed = opts.arrowCollapsed;

      setTextContent = function (element, text) {
        try {
          var contentEle = element.getElementsByClassName("pvtFixedHeader")[0];
          contentEle.textContent = text;
        } catch (e) {
          console.log("empty");
        }
      };

      hasClass = function (element, className) {
        var regExp;
        regExp = new RegExp("(?:^|\\s)" + className + "(?!\\S)", "g");
        return element.className.match(regExp) !== null;
      };
      removeClass = function (element, className) {
        var k, len, name, ref, regExp, results;
        ref = className.split(" ");
        results = [];
        for (k = 0, len = ref.length; k < len; k++) {
          name = ref[k];
          regExp = new RegExp("(?:^|\\s)" + name + "(?!\\S)", "g");
          results.push(element.className = element.className.replace(regExp, ''));
        }
        return results;
      };
      addClass = function (element, className) {
        var k, len, name, ref, results;
        ref = className.split(" ");
        results = [];
        for (k = 0, len = ref.length; k < len; k++) {
          name = ref[k];
          if (!hasClass(element, name)) {
            results.push(element.className += " " + name);
          } else {
            results.push(void 0);
          }
        }
        return results;
      };
      replaceClass = function (element, replaceClassName, byClassName) {
        removeClass(element, replaceClassName);
        return addClass(element, byClassName);
      };
      createElement = function (elementType, className, textContent, attributes, eventHandlers) {
        var attr, e, event, handler, val;
        e = document.createElement(elementType);
        if (className != null) {
          e.className = className;
        }
        if (textContent != null) {
          e.textContent = textContent;
        }
        if (attributes != null) {
          for (attr in attributes) {
            if (!hasProp.call(attributes, attr)) continue;
            val = attributes[attr];
            e.setAttribute(attr, val);
          }
        }
        if (eventHandlers != null) {
          for (event in eventHandlers) {
            if (!hasProp.call(eventHandlers, event)) continue;
            handler = eventHandlers[event];
            e.addEventListener(event, handler);
          }
        }
        return e;
      };
      setAttributes = function (e, attrs) {
        var a, results, v;
        results = [];
        for (a in attrs) {
          if (!hasProp.call(attrs, a)) continue;
          v = attrs[a];
          results.push(e.setAttribute(a, v));
        }
        return results;
      };
      processKeys = function (keysArr, className, opts) {
        var headers, lastIdx, row;
        lastIdx = keysArr[0].length - 1;
        headers = {
          children: []
        };
        row = 0;
        keysArr.reduce((function (_this) {
          return function (val0, k0) {
            var col;
            col = 0;
            k0.reduce(function (acc, curVal, curIdx, arr) {
              var i, k, key, node, ref;
              if (!acc[curVal]) {
                key = k0.slice(0, col + 1);
                acc[curVal] = {
                  row: row,
                  col: col,
                  descendants: 0,
                  children: [],
                  text: curVal,
                  key: key,
                  flatKey: key.join(String.fromCharCode(0)),
                  firstLeaf: null,
                  leaves: 0,
                  parent: col !== 0 ? acc : null,
                  th: createElement("th", className, curVal),
                  childrenSpan: 0
                };
                acc.children.push(curVal);
              }
              if (col > 0) {
                acc.descendants++;
              }
              col++;
              if (curIdx === lastIdx) {
                node = headers;
                for (i = k = 0, ref = lastIdx - 1; 0 <= ref ? k <= ref : k >= ref; i = 0 <= ref ? ++k : --k) {
                  if (!(lastIdx > 0)) {
                    continue;
                  }
                  node[k0[i]].leaves++;
                  if (!node[k0[i]].firstLeaf) {
                    node[k0[i]].firstLeaf = acc[curVal];
                  }
                  node = node[k0[i]];
                }
                return headers;
              }
              return acc[curVal];
            }, headers);
            row++;
            return headers;
          };
        })(this), headers);
        return headers;
      };
      buildAxisHeader = function (axisHeaders, col, attrs, opts) {
        var ah, arrow, hClass;
        ah = {
          text: attrs[col],
          expandedCount: 0,
          expandables: 0,
          attrHeaders: [],
          clickStatus: clickStatusExpanded,
          onClick: collapseAxis
        };
        arrow = arrowExpanded + " ";
        hClass = classExpanded;
        if (col >= opts.collapseAt) {
          arrow = arrowCollapsed + " ";
          hClass = classCollapsed;
          ah.clickStatus = clickStatusCollapsed;
          ah.onClick = expandAxis;
        }
        if (col === attrs.length - 1 || col >= opts.disableFrom || opts.disableExpandCollapse) {
          arrow = "";
        }
        ah.th = createElement("th", "pvtAxisLabel " + hClass, "" + arrow + ah.text);
        if (col < attrs.length - 1 && col < opts.disableFrom && !opts.disableExpandCollapse) {
          ah.th.setAttribute('root-node', '1');
          ah.th.onclick = function (event) {
            event = event || window.event;
            return ah.onClick(axisHeaders, col, attrs, opts);
          };
        }
        axisHeaders.ah.push(ah);
        return ah;
      };
      buildColAxisHeaders = function (thead, rowAttrs, colAttrs, opts) {
        var ah, attr, axisHeaders, col, k, len;
        axisHeaders = {
          collapseAttrHeader: collapseCol,
          expandAttrHeader: expandCol,
          ah: []
        };
        for (col = k = 0, len = colAttrs.length; k < len; col = ++k) {
          attr = colAttrs[col];
          ah = buildAxisHeader(axisHeaders, col, colAttrs, opts.colSubtotalDisplay);
          ah.tr = createElement("tr");
          if (col === 0 && rowAttrs.length !== 0) {
            ah.tr.appendChild(createElement("th", null, null, {
              colspan: rowAttrs.length,
              rowspan: colAttrs.length
            }));
          }
          ah.tr.appendChild(ah.th);
          thead.appendChild(ah.tr);
        }
        return axisHeaders;
      };
      buildRowAxisHeaders = function (thead, rowAttrs, colAttrs, opts) {
        var ah, axisHeaders, col, k, ref, th;
        axisHeaders = {
          collapseAttrHeader: collapseRow,
          expandAttrHeader: expandRow,
          ah: [],
          tr: createElement("tr")
        };
        for (col = k = 0, ref = rowAttrs.length - 1; 0 <= ref ? k <= ref : k >= ref; col = 0 <= ref ? ++k : --k) {
          ah = buildAxisHeader(axisHeaders, col, rowAttrs, opts.rowSubtotalDisplay);
          axisHeaders.tr.appendChild(ah.th);
        }
        if (colAttrs.length !== 0) {
          th = createElement("th");
          axisHeaders.tr.appendChild(th);
        }
        thead.appendChild(axisHeaders.tr);
        return axisHeaders;
      };
      getHeaderText = function (h, attrs, opts) {
        var arrow;
        arrow = " " + arrowExpanded + " ";
        if (h.col === attrs.length - 1 || h.col >= opts.disableFrom || opts.disableExpandCollapse || h.children.length === 0) {
          arrow = "";
        }
        return "" + arrow + h.text;
      };
      buildColHeader = function (axisHeaders, attrHeaders, h, rowAttrs, colAttrs, node, opts) {
        var ah, chKey, k, len, ref, ref1;
        ref = h.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          buildColHeader(axisHeaders, attrHeaders, h[chKey], rowAttrs, colAttrs, node, opts);
        }
        ah = axisHeaders.ah[h.col];
        ah.attrHeaders.push(h);
        h.node = node.counter;
        h.onClick = collapseCol;
        // addClass(h.th, classColShow + " col" + h.row + " colcol" + h.col + " " + classColExpanded);
        addClass(h.th, classColShow + " col" + h.row + " colcol" + h.col);
        h.th.setAttribute("data-colnode", h.node);
        if (h.children.length !== 0) {
          h.th.colSpan = h.childrenSpan;
        }
        if (h.children.length === 0 && rowAttrs.length !== 0) {
          h.th.rowSpan = 2;
          h.th.setAttribute("key-index", h.row);
          addClass(h.th, "pvtSortable");
          if (h.row == sortInfo.colIndex && JSON.stringify(colKeys[h.row]) === sortInfo.colKey) {
            addClass(h.th, sortInfo.direction == -1 ? "pvtSortDesc" : sortInfo.direction == 1 ? "pvtSortAsc" : "");
          }

          b = pivotData;
          // h.th.onclick = function (event) {
          //   curPage = 1;
          //   sortInfo.colIndex = $(this).attr('key-index');
          //
          //   if (sortInfo.colIndex < 0) {
          //     return;
          //   }
          //   sortInfo.colKey = JSON.stringify(colKeys[sortInfo.colIndex]);
          //
          //   if (hasClass(this, "pvtSortDesc")) {
          //     sortInfo.direction = 1;
          //   } else if (hasClass(this, "pvtSortAsc")) {
          //     sortInfo.direction = 0;
          //   } else {
          //     sortInfo.direction = -1;
          //   }
          //
          //   refresh();
          // };
        }

        h.th.textContent = getHeaderText(h, colAttrs, opts.colSubtotalDisplay);
        if (h.children.length !== 0 && h.col < opts.colSubtotalDisplay.disableFrom) {
          ah.expandables++;
          ah.expandedCount += 1;
          if (!opts.colSubtotalDisplay.hideOnExpand) {
            h.th.colSpan++;
          }
          // if (!opts.colSubtotalDisplay.disableExpandCollapse) {
          //   h.th.onclick = function (event) {
          //     event = event || window.event;
          //     return h.onClick(axisHeaders, h, opts.colSubtotalDisplay);
          //   };
          // }
          h.sTh = createElement("th", "pvtColLabelFiller " + classColShow + " col" + h.row + " colcol" + h.col + " " + classColExpanded);
          h.sTh.setAttribute("data-colnode", h.node);
          h.sTh.rowSpan = colAttrs.length - h.col;
          if (opts.colSubtotalDisplay.hideOnExpand) {
            replaceClass(h.sTh, classColShow, classColHide);
          }
          h[h.children[0]].tr.appendChild(h.sTh);
        }
        if ((ref1 = h.parent) != null) {
          ref1.childrenSpan += h.th.colSpan;
        }
        h.clickStatus = clickStatusExpanded;
        ah.tr.appendChild(h.th);
        h.tr = ah.tr;
        attrHeaders.push(h);
        return node.counter++;
      };
      buildRowTotalsHeader = function (tr, rowAttrs, colAttrs) {
        var th;
        th = createElement("th", "pvtTotalLabel rowTotal", opts.localeStrings.totals, {
          rowspan: colAttrs.length === 0 ? 1 : colAttrs.length + (rowAttrs.length === 0 ? 0 : 1)
        });
        return tr.appendChild(th);
      };
      buildRowHeader = function (tbody, axisHeaders, attrHeaders, h, rowAttrs, colAttrs, node, opts) {
        var ah, chKey, firstChild, k, len, ref, ref1;
        ref = h.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          buildRowHeader(tbody, axisHeaders, attrHeaders, h[chKey], rowAttrs, colAttrs, node, opts);
        }
        ah = axisHeaders.ah[h.col];
        ah.attrHeaders.push(h);
        h.node = node.counter;
        h.onClick = collapseRow;
        if (h.children.length !== 0) {
          firstChild = h[h.children[0]];
        }
        addClass(h.th, classRowShow + " row" + h.row + " rowcol" + h.col + " " + classRowExpanded);
        h.th.setAttribute("data-rownode", h.node);


        if (h.col === rowAttrs.length - 1 && colAttrs.length !== 0) {
          h.th.colSpan = 2;
        }
        if (h.children.length !== 0) {
          h.th.rowSpan = h.childrenSpan;
        }
        h.th.textContent = getHeaderText(h, rowAttrs, opts.rowSubtotalDisplay);
        // var content = createElement("div", "pvtContent");
        // h.th.appendChild(content);

        h.tr = createElement("tr", "row" + h.row);
        h.tr.appendChild(h.th);
        if (h.children.length === 0) {
          tbody.appendChild(h.tr);
        } else {
          tbody.insertBefore(h.tr, firstChild.tr);
        }
        if (h.children.length !== 0 && h.col < opts.rowSubtotalDisplay.disableFrom) {
          ++ah.expandedCount;
          ++ah.expandables;
          if (!opts.rowSubtotalDisplay.disableExpandCollapse) {
            h.th.onclick = function (event) {
              event = event || window.event;
              return h.onClick(axisHeaders, h, opts.rowSubtotalDisplay);
            };
          }
          h.sTh = createElement("th", "pvtRowLabel row" + h.row + " rowcol" + h.col + " " + classRowExpanded + " " + classRowShow);
          if (opts.rowSubtotalDisplay.hideOnExpand) {
            replaceClass(h.sTh, classRowShow, classRowHide);
          }
          h.sTh.setAttribute("data-rownode", h.node);
          h.sTh.colSpan = rowAttrs.length - (h.col + 1) + (colAttrs.length !== 0 ? 1 : 0);
          if (opts.rowSubtotalDisplay.displayOnTop) {
            h.tr.appendChild(h.sTh);
          } else {
            h.th.rowSpan += 1;
            h.sTr = createElement("tr", "row" + h.row);
            h.sTr.appendChild(h.sTh);
            tbody.appendChild(h.sTr);
          }
        }
        if (h.children.length !== 0) {
          h.th.rowSpan++;
        }
        if ((ref1 = h.parent) != null) {
          ref1.childrenSpan += h.th.rowSpan;
        }
        h.clickStatus = clickStatusExpanded;
        attrHeaders.push(h);
        return node.counter++;
      };
      getTableEventHandlers = function (value, rowKey, colKey, rowAttrs, colAttrs, opts) {
        var attr, event, eventHandlers, filters, handler, i, ref, ref1;
        if (!((ref = opts.table) != null ? ref.eventHandlers : void 0)) {
          return;
        }
        eventHandlers = {};
        ref1 = opts.table.eventHandlers;
        for (event in ref1) {
          if (!hasProp.call(ref1, event)) continue;
          handler = ref1[event];
          filters = {};
          for (i in colAttrs) {
            if (!hasProp.call(colAttrs, i)) continue;
            attr = colAttrs[i];
            if (colKey[i] != null) {
              filters[attr] = colKey[i];
            }
          }
          for (i in rowAttrs) {
            if (!hasProp.call(rowAttrs, i)) continue;
            attr = rowAttrs[i];
            if (rowKey[i] != null) {
              filters[attr] = rowKey[i];
            }
          }
          eventHandlers[event] = function (e) {
            return handler(e, value, filters, pivotData);
          };
        }
        return eventHandlers;
      };
      buildValues = function (tbody, colAttrHeaders, rowAttrHeaders, rowAttrs, colAttrs, opts) {
        var aggregator, ch, cls, k, l, len, len1, rCls, ref, results, rh, td, totalAggregator, tr, val;
        results = [];
        for (k = 0, len = rowAttrHeaders.length; k < len; k++) {
          rh = rowAttrHeaders[k];
          if (!(rh.col === rowAttrs.length - 1 || (rh.children.length !== 0 && rh.col < opts.rowSubtotalDisplay.disableFrom))) {
            continue;
          }
          rCls = "pvtVal row" + rh.row + " rowcol" + rh.col + " " + classRowExpanded;
          if (rh.children.length > 0) {
            rCls += " pvtRowSubtotal";
            rCls += opts.rowSubtotalDisplay.hideOnExpand ? " " + classRowHide : "  " + classRowShow;
          } else {
            rCls += " " + classRowShow;
          }
          tr = rh.sTr ? rh.sTr : rh.tr;
          for (l = 0, len1 = colAttrHeaders.length; l < len1; l++) {
            ch = colAttrHeaders[l];
            if (!(ch.col === colAttrs.length - 1 || (ch.children.length !== 0 && ch.col < opts.colSubtotalDisplay.disableFrom))) {
              continue;
            }
            aggregator = (ref = tree[rh.flatKey][ch.flatKey]) != null ? ref : {
              value: (function () {
                return null;
              }),
              format: function () {
                return "";
              }
            };
            val = aggregator.value();
            cls = " " + rCls + " col" + ch.row + " colcol" + ch.col + " " + classColExpanded;
            if (ch.children.length > 0) {
              cls += " pvtColSubtotal";
              cls += opts.colSubtotalDisplay.hideOnExpand ? " " + classColHide : " " + classColShow;
            } else {
              cls += " " + classColShow;
            }
            td = createElement("td", cls, aggregator.format(val), {
              "data-value": val,
              "data-rownode": rh.node,
              "data-colnode": ch.node
            }, getTableEventHandlers(val, rh.key, ch.key, rowAttrs, colAttrs, opts));
            tr.appendChild(td);
          }
          totalAggregator = rowTotals[rh.flatKey];
          val = totalAggregator.value();
          td = createElement("td", "pvtTotal rowTotal " + rCls, totalAggregator.format(val), {
            "data-value": val,
            "data-row": "row" + rh.row,
            "data-rowcol": "col" + rh.col,
            "data-rownode": rh.node
          }, getTableEventHandlers(val, rh.key, [], rowAttrs, colAttrs, opts));
          results.push(tr.appendChild(td));
        }
        return results;
      };
      buildColTotalsHeader = function (rowAttrs, colAttrs) {
        var colspan, th, tr;
        tr = createElement("tr");
        colspan = rowAttrs.length + (colAttrs.length === 0 ? 0 : 1);
        th = createElement("th", "pvtTotalLabel colTotal", opts.localeStrings.totals, {
          colspan: colspan
        });
        tr.appendChild(th);
        return tr;
      };
      buildColTotals = function (tr, attrHeaders, rowAttrs, colAttrs, opts) {
        var clsNames, h, k, len, results, td, totalAggregator, val;
        results = [];
        for (k = 0, len = attrHeaders.length; k < len; k++) {
          h = attrHeaders[k];
          if (!(h.col === colAttrs.length - 1 || (h.children.length !== 0 && h.col < opts.colSubtotalDisplay.disableFrom))) {
            continue;
          }
          clsNames = "pvtVal pvtTotal colTotal " + classColExpanded + " col" + h.row + " colcol" + h.col;
          if (h.children.length !== 0) {
            clsNames += " pvtColSubtotal";
            clsNames += opts.colSubtotalDisplay.hideOnExpand ? " " + classColHide : " " + classColShow;
          } else {
            clsNames += " " + classColShow;
          }
          totalAggregator = colTotals[h.flatKey];
          val = totalAggregator.value();
          td = createElement("td", clsNames, totalAggregator.format(val), {
            "data-value": val,
            "data-for": "col" + h.col,
            "data-colnode": "" + h.node
          }, getTableEventHandlers(val, [], h.key, rowAttrs, colAttrs, opts));
          results.push(tr.appendChild(td));
        }
        return results;
      };
      buildGrandTotal = function (tbody, tr, rowAttrs, colAttrs, opts) {
        var td, totalAggregator, val;
        totalAggregator = allTotal;
        val = totalAggregator.value();
        td = createElement("td", "pvtGrandTotal", totalAggregator.format(val), {
          "data-value": val
        }, getTableEventHandlers(val, [], [], rowAttrs, colAttrs, opts));
        tr.appendChild(td);
        return tbody.appendChild(tr);
      };
      collapseAxisHeaders = function (axisHeaders, col, opts) {
        var ah, collapsible, i, k, ref, ref1, results;
        collapsible = Math.min(axisHeaders.ah.length - 2, opts.disableFrom - 1);
        if (col > collapsible) {
          return;
        }
        results = [];
        for (i = k = ref = col, ref1 = collapsible; ref <= ref1 ? k <= ref1 : k >= ref1; i = ref <= ref1 ? ++k : --k) {
          ah = axisHeaders.ah[i];
          replaceClass(ah.th, classExpanded, classCollapsed);
          // ah.th.textContent = " " + arrowCollapsed +arrowCollapsed + " " + ah.text;
          setTextContent(ah.th, " " + arrowCollapsed + " " + ah.text);

          ah.clickStatus = clickStatusCollapsed;
          jQuery( '.pvtTableWrapper .pvtTable thead tr:first-child th:first-child div.pvtFixedHeader' ).html( "<img alt='dummy-image' class='negative-image' title='dummy-image'  src='/sites/all/modules/custom/dd_accessibility/images/dummy-image.png'>" );
          jQuery( '.pvtTableWrapper .pvtTable thead tr:last-child th:last-child div.pvtFixedHeader' ).html( "<img alt='dummy-image'  class='negative-image' title='dummy-image '  src='/sites/all/modules/custom/dd_accessibility/images/dummy-image.png'>" );
          jQuery( '.pvtTableWrapper .pvtTable tbody tr th:nth-child(2).rowshow.rowcollapsed div.pvtFixedHeader' ).html( "<img class='tbody-image negative-image' alt='dummy-image' title='dummy-image'  src='/sites/all/modules/custom/dd_accessibility/images/dummy-tbody.png'>" );        
          results.push(ah.onClick = expandAxis);
          }
        return results;
      };
      adjustAxisHeader = function (axisHeaders, col, opts) {
        var ah;
        ah = axisHeaders.ah[col];
        if (ah.expandedCount === 0) {
          return collapseAxisHeaders(axisHeaders, col, opts);
        } else if (ah.expandedCount === ah.expandables) {
          replaceClass(ah.th, classCollapsed, classExpanded);
          // ah.th.textContent = " " + arrowExpanded + " " + ah.text;
          setTextContent(ah.th, " " + arrowExpanded + " " + ah.text);
          ah.clickStatus = clickStatusExpanded;
          jQuery( '.pvtTableWrapper .pvtTable tbody tr th:nth-child(2).rowshow.rowexpanded div.pvtFixedHeader' ).html( "<img class='tbody-image negative-image' alt='dummy-image' title='dummy-image' style='width:100%; height: 100%' src='/sites/all/modules/custom/dd_accessibility/images/tbody-dummy-expanded.png'>" );
          return ah.onClick = collapseAxis;
        }
      };
      hideChildCol = function (ch) {
        return $(ch.th).closest('table.pvtTable').find("tbody tr td[data-colnode=\"" + ch.node + "\"], th[data-colnode=\"" + ch.node + "\"]").removeClass(classColShow).addClass(classColHide);
      };
      collapseHiddenColSubtotal = function (h, opts) {
        $(h.th).closest('table.pvtTable').find("tbody tr td[data-colnode=\"" + h.node + "\"], th[data-colnode=\"" + h.node + "\"]").removeClass(classColExpanded).addClass(classColCollapsed);
        if (h.children.length !== 0) {
          h.th.textContent = " " + arrowCollapsed + " " + h.text;
        }
        return h.th.colSpan = 1;
      };
      collapseShowColSubtotal = function (h, opts) {
        $(h.th).closest('table.pvtTable').find("tbody tr td[data-colnode=\"" + h.node + "\"], th[data-colnode=\"" + h.node + "\"]").removeClass(classColExpanded).addClass(classColCollapsed).removeClass(classColHide).addClass(classColShow);
        if (h.children.length !== 0) {
          h.th.textContent = " " + arrowCollapsed + " " + h.text;
        }
        return h.th.colSpan = 1;
      };
      collapseChildCol = function (ch, h) {
        var chKey, k, len, ref;
        ref = ch.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          if (hasClass(ch[chKey].th, classColShow)) {
            collapseChildCol(ch[chKey], h);
          }
        }
        return hideChildCol(ch);
      };
      collapseCol = function (axisHeaders, h, opts) {
        var chKey, colSpan, k, len, p, ref;
        colSpan = h.th.colSpan - 1;
        ref = h.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          if (hasClass(h[chKey].th, classColShow)) {
            collapseChildCol(h[chKey], h);
          }
        }
        if (h.col < opts.disableFrom) {
          if (hasClass(h.th, classColHide)) {
            collapseHiddenColSubtotal(h, opts);
          } else {
            collapseShowColSubtotal(h, opts);
          }
        }
        p = h.parent;
        while (p) {
          p.th.colSpan -= colSpan;
          p = p.parent;
        }
        h.clickStatus = clickStatusCollapsed;
        h.onClick = expandCol;
        axisHeaders.ah[h.col].expandedCount--;
        return adjustAxisHeader(axisHeaders, h.col, opts);
      };
      showChildCol = function (ch) {
        return $(ch.th).closest('table.pvtTable').find("tbody tr td[data-colnode=\"" + ch.node + "\"], th[data-colnode=\"" + ch.node + "\"]").removeClass(classColHide).addClass(classColShow);
      };
      expandHideColSubtotal = function (h) {
        $(h.th).closest('table.pvtTable').find("tbody tr td[data-colnode=\"" + h.node + "\"], th[data-colnode=\"" + h.node + "\"]").removeClass(classColCollapsed + " " + classColShow).addClass(classColExpanded + " " + classColHide);
        replaceClass(h.th, classColHide, classColShow);
        // return h.th.textContent = " " + arrowExpanded + " " + h.text;
        return setTextContent(h.th, " " + arrowExpanded + " " + h.text);
      };
      expandShowColSubtotal = function (h) {
        $(h.th).closest('table.pvtTable').find("tbody tr td[data-colnode=\"" + h.node + "\"], th[data-colnode=\"" + h.node + "\"]").removeClass(classColCollapsed + " " + classColHide).addClass(classColExpanded + " " + classColShow);
        h.th.colSpan++;
        // return h.th.textContent = " " + arrowExpanded + " " + h.text;
        return setTextContent(h.th, " " + arrowExpanded + " " + h.text);
      };
      expandChildCol = function (ch, opts) {
        var chKey, k, len, ref, results;
        if (ch.children.length !== 0 && opts.hideOnExpand && ch.clickStatus === clickStatusExpanded) {
          replaceClass(ch.th, classColHide, classColShow);
        } else {
          showChildCol(ch);
        }
        if (ch.sTh && ch.clickStatus === clickStatusExpanded && opts.hideOnExpand) {
          replaceClass(ch.sTh, classColShow, classColHide);
        }
        if (ch.clickStatus === clickStatusExpanded || ch.col >= opts.disableFrom) {
          ref = ch.children;
          results = [];
          for (k = 0, len = ref.length; k < len; k++) {
            chKey = ref[k];
            results.push(expandChildCol(ch[chKey], opts));
          }
          return results;
        }
      };
      expandCol = function (axisHeaders, h, opts) {
        var ch, chKey, colSpan, k, len, p, ref;
        if (h.clickStatus === clickStatusExpanded) {
          adjustAxisHeader(axisHeaders, h.col, opts);
          return;
        }
        colSpan = 0;
        ref = h.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          ch = h[chKey];
          expandChildCol(ch, opts);
          colSpan += ch.th.colSpan;
        }
        h.th.colSpan = colSpan;
        if (h.col < opts.disableFrom) {
          if (opts.hideOnExpand) {
            expandHideColSubtotal(h);
            --colSpan;
          } else {
            expandShowColSubtotal(h);
          }
        }
        p = h.parent;
        while (p) {
          p.th.colSpan += colSpan;
          p = p.parent;
        }
        h.clickStatus = clickStatusExpanded;
        h.onClick = collapseCol;
        axisHeaders.ah[h.col].expandedCount++;
        return adjustAxisHeader(axisHeaders, h.col, opts);
      };
      hideChildRow = function (ch, opts) {
        var cell, k, l, len, len1, ref, ref1, results;
        ref = ch.tr.querySelectorAll("th, td");
        for (k = 0, len = ref.length; k < len; k++) {
          cell = ref[k];
          replaceClass(cell, classRowShow, classRowHide);
        }
        if (ch.sTr) {
          ref1 = ch.sTr.querySelectorAll("th, td");
          results = [];
          for (l = 0, len1 = ref1.length; l < len1; l++) {
            cell = ref1[l];
            results.push(replaceClass(cell, classRowShow, classRowHide));
          }
          return results;
        }
      };
      collapseShowRowSubtotal = function (h, opts) {
        var cell, k, l, len, len1, ref, ref1, results;
        // h.th.textContent = " " + arrowCollapsed + " " + h.text;
        setTextContent(h.th, " " + arrowCollapsed + " " + h.text);

        var content = h.th.getElementsByClassName("pvtFixedHeader")[0];
        content.style.height = h.th.parentElement.clientHeight + "px";

        ref = h.tr.querySelectorAll("th, td");
        for (k = 0, len = ref.length; k < len; k++) {
          cell = ref[k];
          removeClass(cell, classRowExpanded + " " + classRowHide);
          addClass(cell, classRowCollapsed + " " + classRowShow);
        }
        if (h.sTr) {
          ref1 = h.sTr.querySelectorAll("th, td");
          results = [];
          for (l = 0, len1 = ref1.length; l < len1; l++) {
            cell = ref1[l];
            removeClass(cell, classRowExpanded + " " + classRowHide);
            results.push(addClass(cell, classRowCollapsed + " " + classRowShow));
          }
          return results;
        }
      };
      collapseChildRow = function (ch, h, opts) {
        var chKey, k, len, ref;
        ref = ch.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          collapseChildRow(ch[chKey], h, opts);
        }
        return hideChildRow(ch, opts);
      };
      collapseRow = function (axisHeaders, h, opts) {
        var chKey, k, len, ref;
        ref = h.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          collapseChildRow(h[chKey], h, opts);
        }
        collapseShowRowSubtotal(h, opts);
        h.clickStatus = clickStatusCollapsed;
        h.onClick = expandRow;
        axisHeaders.ah[h.col].expandedCount--;
        return adjustAxisHeader(axisHeaders, h.col, opts);
      };
      showChildRow = function (ch, opts) {
        var cell, k, l, len, len1, ref, ref1, results;
        ref = ch.tr.querySelectorAll("th, td");
        for (k = 0, len = ref.length; k < len; k++) {
          cell = ref[k];
          replaceClass(cell, classRowHide, classRowShow);
        }
        if (ch.sTr) {
          ref1 = ch.sTr.querySelectorAll("th, td");
          results = [];
          for (l = 0, len1 = ref1.length; l < len1; l++) {
            cell = ref1[l];
            results.push(replaceClass(cell, classRowHide, classRowShow));
          }
          return results;
        }
      };
      expandShowRowSubtotal = function (h, opts) {
        var cell, k, l, len, len1, ref, ref1, results;
        // h.th.textContent = " " + arrowExpanded + " " + h.text;
        setTextContent(h.th, " " + arrowExpanded + " " + h.text);
        var content = h.th.getElementsByClassName("pvtFixedHeader")[0];
        content.style.height = content.getAttribute("origin-height");

        ref = h.tr.querySelectorAll("th, td");
        for (k = 0, len = ref.length; k < len; k++) {
          cell = ref[k];
          removeClass(cell, classRowCollapsed + " " + classRowHide);
          addClass(cell, classRowExpanded + " " + classRowShow);
        }
        if (h.sTr) {
          ref1 = h.sTr.querySelectorAll("th, td");
          results = [];
          for (l = 0, len1 = ref1.length; l < len1; l++) {
            cell = ref1[l];
            removeClass(cell, classRowCollapsed + " " + classRowHide);
            results.push(addClass(cell, classRowExpanded + " " + classRowShow));
          }
          return results;
        }
      };
      expandHideRowSubtotal = function (h, opts) {
        var cell, k, l, len, len1, ref, ref1, results;
        // h.th.textContent = " " + arrowExpanded + " " + h.text;
        setTextContent(h.th, " " + arrowExpanded + " " + h.text);

        ref = h.tr.querySelectorAll("th, td");
        for (k = 0, len = ref.length; k < len; k++) {
          cell = ref[k];
          removeClass(cell, classRowCollapsed + " " + classRowShow);
          addClass(cell, classRowExpanded + " " + classRowHide);
        }
        removeClass(h.th, classRowCollapsed + " " + classRowHide);
        addClass(cell, classRowExpanded + " " + classRowShow);
        if (h.sTr) {
          ref1 = h.sTr.querySelectorAll("th, td");
          results = [];
          for (l = 0, len1 = ref1.length; l < len1; l++) {
            cell = ref1[l];
            removeClass(cell, classRowCollapsed + " " + classRowShow);
            results.push(addClass(cell, classRowExpanded + " " + classRowHide));
          }
          return results;
        }
      };
      expandChildRow = function (ch, opts) {
        var chKey, k, len, ref, results;
        if (ch.children.length !== 0 && opts.hideOnExpand && ch.clickStatus === clickStatusExpanded) {
          replaceClass(ch.th, classRowHide, classRowShow);
        } else {
          showChildRow(ch, opts);
        }
        if (ch.sTh && ch.clickStatus === clickStatusExpanded && opts.hideOnExpand) {
          replaceClass(ch.sTh, classRowShow, classRowHide);
        }
        if (ch.clickStatus === clickStatusExpanded || ch.col >= opts.disableFrom) {
          ref = ch.children;
          results = [];
          for (k = 0, len = ref.length; k < len; k++) {
            chKey = ref[k];
            results.push(expandChildRow(ch[chKey], opts));
          }
          return results;
        }
      };
      expandRow = function (axisHeaders, h, opts) {
        var ch, chKey, k, len, ref;
        if (h.clickStatus === clickStatusExpanded) {
          adjustAxisHeader(axisHeaders, h.col, opts);
          return;
        }
        ref = h.children;
        for (k = 0, len = ref.length; k < len; k++) {
          chKey = ref[k];
          ch = h[chKey];
          expandChildRow(ch, opts);
        }
        if (h.children.length !== 0) {
          if (opts.hideOnExpand) {
            expandHideRowSubtotal(h, opts);
          } else {
            expandShowRowSubtotal(h, opts);
          }
        }
        h.clickStatus = clickStatusExpanded;
        h.onClick = collapseRow;
        axisHeaders.ah[h.col].expandedCount++;
        return adjustAxisHeader(axisHeaders, h.col, opts);
      };
      collapseAxis = function (axisHeaders, col, attrs, opts) {
        var collapsible, h, i, k, ref, ref1, results;
        collapsible = Math.min(attrs.length - 2, opts.disableFrom - 1);
        if (col > collapsible) {
          return;
        }
        results = [];
        for (i = k = ref = collapsible, ref1 = col; k >= ref1; i = k += -1) {
          results.push((function () {
            var l, len, ref2, results1;
            ref2 = axisHeaders.ah[i].attrHeaders;
            results1 = [];
            for (l = 0, len = ref2.length; l < len; l++) {
              h = ref2[l];
              if (h.clickStatus === clickStatusExpanded && h.children.length !== 0) {
                results1.push(axisHeaders.collapseAttrHeader(axisHeaders, h, opts));
              }
            }
            return results1;
          })());
        }
        return results;
      };
      expandAxis = function (axisHeaders, col, attrs, opts) {
        var ah, h, i, k, ref, results;
        ah = axisHeaders.ah[col];
        results = [];
        for (i = k = 0, ref = col; 0 <= ref ? k <= ref : k >= ref; i = 0 <= ref ? ++k : --k) {
          results.push((function () {
            var l, len, ref1, results1;
            ref1 = axisHeaders.ah[i].attrHeaders;
            results1 = [];
            for (l = 0, len = ref1.length; l < len; l++) {
              h = ref1[l];
              results1.push(axisHeaders.expandAttrHeader(axisHeaders, h, opts));
            }
            return results1;
          })());
        }
        return results;
      };
      main = function (rowAttrs, rowKeys, colAttrs, colKeys) {

        container = createElement("div", "pvtTableContainer");

        //add search elements
        searchSection = createElement("div", "pvtTableSearchSection");
        searchInput1 = document.getElementById("searchInput");
        searchInput1.onchange = function (event) {
          globalSearchKey = this.value.toLowerCase();
          globalSearchValue = "";
          refresh();
        }

        $(".resetSearch").click(function(){
          location.reload();
        });

        searchInput2 = document.getElementById("filterItems");
        searchInput2.onchange = function (event) {
          console.log(this.value);
          globalFilterKey = this.value.toLowerCase();
          globalFilterValue = "";
          refresh();
        }


        //add pagination elements
        paginateSection = createElement("div", "pvtTablePageSection");
        paginateBtnWrapper = createElement("span");

        paginateFirstBtn = createElement("a", "paginate_button", "First");
        paginateBtnWrapper.appendChild(paginateFirstBtn);

        paginateFirstBtn.onclick = function (event) {
          if (curPage != 1) {
            curPage = 1;
            refresh();
          }
        }

        paginatePrevBtn = createElement("a", "paginate_button", "Prev");
        paginateBtnWrapper.appendChild(paginatePrevBtn);

        const totalPage = Math.ceil(pivotData.rowKeys.length / rowsPerPage);


        if (curPage > totalPage) {
          curPage = 1;
        }

        var pageNumArray = [];
        // -1 means (...)
        if (totalPage >= 14) {
          if (curPage >= 8 && curPage <= totalPage - 8) {
            pageNumArray = [1, 2, -1];
            for (var i = curPage - 3; i < curPage + 4; i++) {
              pageNumArray.push(i);
            }
            pageNumArray = pageNumArray.concat([-1, totalPage - 1, totalPage]);
          } else if (curPage < 8) {
            pageNumArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, totalPage - 1, totalPage];
          } else {
            pageNumArray = [1, 2, -1];
            for (var i = totalPage - 9; i < totalPage + 1; i++) {
              pageNumArray.push(i);
            }
          }
        } else {
          for (var i = 1; i < totalPage + 1; i++) {
            pageNumArray.push(i);
          }
        }

        for (var i = 0; i < pageNumArray.length; i++) {
          var paginateItem;
          if (pageNumArray[i] === -1) {
            paginateItem = createElement("span", "paginate_more", "...");
          } else {
            paginateItem = createElement("a", "paginate_button", pageNumArray[i], {
              "data-dt-idx": pageNumArray[i]
            });
            if (pageNumArray[i] == curPage) {
              addClass(paginateItem, "current");
            }
            paginateItem.onclick = function (event) {
              const pageNum = Number(this.getAttribute("data-dt-idx"));
              if (pageNum != curPage) {
                curPage = pageNum;
                refresh();
              }
            };
          }
          paginateBtnWrapper.appendChild(paginateItem);
        }

        paginateNextBtn = createElement("a", "paginate_button", "Next");
        paginateBtnWrapper.appendChild(paginateNextBtn);

        paginatePrevBtn.onclick = function (event) {
          if (curPage > 1) {
            curPage--;
            refresh();
          }
        }
        paginateNextBtn.onclick = function (event) {
          if (curPage < totalPage) {
            curPage++;
            refresh();
          }
        }

        paginateLastBtn = createElement("a", "paginate_button", "Last");
        paginateBtnWrapper.appendChild(paginateLastBtn);

        paginateLastBtn.onclick = function (event) {
          if (curPage != totalPage) {
            curPage = totalPage;
            refresh();
          }
        }

        paginateSection.appendChild(paginateBtnWrapper);

        //pivot table
        //pivotData.rowKeys = pivotData.rowKeys.slice(curPage * rowsPerPage, ( curPage + 1 ) * rowsPerPage);
        // pivotData.input = pivotData.input.slice(curPage * rowsPerPage, ( curPage + 1 ) * rowsPerPage);


        var chKey, colAttrHeaders, colAxisHeaders, colKeyHeaders, k, l, len, len1, node, ref, ref1, result, rowAttrHeaders, rowAxisHeaders, rowKeyHeaders, tbody, thead, tr;
        rowAttrHeaders = [];
        colAttrHeaders = [];
        if (colAttrs.length !== 0 && colKeys.length !== 0) {
          colKeyHeaders = processKeys(colKeys, "pvtColLabel");
        }
        if (rowAttrs.length !== 0 && rowKeys.length !== 0) {
          rowKeyHeaders = processKeys(rowKeys, "pvtRowLabel");
        }
        result = createElement("table", "pvtTable", null, {
          style: "display: none;",
          id: "pvtTable"
        });
        thead = createElement("thead");
        result.appendChild(thead);
        if (colAttrs.length !== 0 && colKeys.length !== 0) {
          colAxisHeaders = buildColAxisHeaders(thead, rowAttrs, colAttrs, opts);
          node = {
            counter: 0
          };
          ref = colKeyHeaders.children;
          for (k = 0, len = ref.length; k < len; k++) {
            chKey = ref[k];
            buildColHeader(colAxisHeaders, colAttrHeaders, colKeyHeaders[chKey], rowAttrs, colAttrs, node, opts);
          }
          buildRowTotalsHeader(colAxisHeaders.ah[0].tr, rowAttrs, colAttrs);
        }
        tbody = createElement("tbody");
        result.appendChild(tbody);
        if (rowAttrs.length !== 0 && rowKeys.length !== 0) {
          rowAxisHeaders = buildRowAxisHeaders(thead, rowAttrs, colAttrs, opts);
          if (colAttrs.length === 0) {
            buildRowTotalsHeader(rowAxisHeaders.tr, rowAttrs, colAttrs);
          }
          node = {
            counter: 0
          };
          ref1 = rowKeyHeaders.children;
          for (l = 0, len1 = ref1.length; l < len1; l++) {
            chKey = ref1[l];
            buildRowHeader(tbody, rowAxisHeaders, rowAttrHeaders, rowKeyHeaders[chKey], rowAttrs, colAttrs, node, opts);
          }
        }
        buildValues(tbody, colAttrHeaders, rowAttrHeaders, rowAttrs, colAttrs, opts);
        tr = buildColTotalsHeader(rowAttrs, colAttrs);
        if (colAttrs.length > 0) {
          buildColTotals(tr, colAttrHeaders, rowAttrs, colAttrs, opts);
        }
        buildGrandTotal(tbody, tr, rowAttrs, colAttrs, opts);
        // collapseAxis(colAxisHeaders, opts.colSubtotalDisplay.collapseAt, colAttrs, opts.colSubtotalDisplay);
        // collapseAxis(rowAxisHeaders, opts.rowSubtotalDisplay.collapseAt, rowAttrs, opts.rowSubtotalDisplay);
        result.setAttribute("data-numrows", rowKeys.length);
        result.setAttribute("data-numcols", colKeys.length);
        result.style.display = "";



        // pivotTable = $.pivotUtilities.renderers["Table"](pivotData, opts);

        //append all children to container
        container.appendChild(searchSection);
        pivotTableWrapper = createElement("div", "pvtTableWrapper");
        if (rowKeys.length != 0 && colKeys.length != 0) {
          pivotTableWrapper.appendChild(result);
          container.appendChild(pivotTableWrapper);
          container.appendChild(paginateSection);
        } else {
          container.appendChild(createElement("h2", "alert-no-data", "No matching records found"));
        }

        return container;
      };

      refresh = function () {
        $(".pvtRenderer").change();
      }

      adjustPagination = function () {
        curPageGroup = Math.floor(curPage / pagesPerGroup);
        refresh();
      }
      return main(rowAttrs, rowKeys, colAttrs, colKeys);


    };
    $.pivotUtilities.custom_renderers = {
      "Table With Subtotal": function (pvtData, opts) {
        return SubtotalRenderer(pvtData, opts);
      },
      "Table With Pagination": function (pvtData, opts) {
        return SubtotalRenderer(pvtData, opts);
      },
      "Table With Subtotal Bar Chart": function (pvtData, opts) {
        return $(SubtotalRenderer(pvtData, opts)).barchart();
      },
      "Table With Subtotal Heatmap": function (pvtData, opts) {
        return $(SubtotalRenderer(pvtData, opts)).heatmap("heatmap", opts);
      },
      "Table With Subtotal Row Heatmap": function (pvtData, opts) {
        return $(SubtotalRenderer(pvtData, opts)).heatmap("rowheatmap", opts);
      },
      "Table With Subtotal Col Heatmap": function (pvtData, opts) {
        return $(SubtotalRenderer(pvtData, opts)).heatmap("colheatmap", opts);
      }
    };
    usFmtPct = $.pivotUtilities.numberFormat({
      digitsAfterDecimal: 1,
      scaler: 100,
      suffix: "%"
    });
    aggregatorTemplates = $.pivotUtilities.aggregatorTemplates;
    subtotalAggregatorTemplates = {
      fractionOf: function (wrapped, type, formatter) {
        if (type == null) {
          type = "row";
        }
        if (formatter == null) {
          formatter = usFmtPct;
        }
        return function () {
          var x;
          x = 1 <= arguments.length ? slice.call(arguments, 0) : [];
          return function (data, rowKey, colKey) {
            if (typeof rowKey === "undefined") {
              rowKey = [];
            }
            if (typeof colKey === "undefined") {
              colKey = [];
            }
            return {
              selector: {
                row: [rowKey.slice(0, -1), []],
                col: [[], colKey.slice(0, -1)]
              }[type],
              inner: wrapped.apply(null, x)(data, rowKey, colKey),
              push: function (record) {
                return this.inner.push(record);
              },
              format: formatter,
              value: function () {
                return this.inner.value() / data.getAggregator.apply(data, this.selector).inner.value();
              },
              numInputs: wrapped.apply(null, x)().numInputs
            };
          };
        };
      }
    };
    $.pivotUtilities.subtotalAggregatorTemplates = subtotalAggregatorTemplates;
    return $.pivotUtilities.subtotal_aggregators = (function (tpl, sTpl) {
      return {
        "Sum As Fraction Of Parent Row": sTpl.fractionOf(tpl.sum(), "row", usFmtPct),
        "Sum As Fraction Of Parent Column": sTpl.fractionOf(tpl.sum(), "col", usFmtPct),
        "Count As Fraction Of Parent Row": sTpl.fractionOf(tpl.count(), "row", usFmtPct),
        "Count As Fraction Of Parent Column": sTpl.fractionOf(tpl.count(), "col", usFmtPct)
      };
    })(aggregatorTemplates, subtotalAggregatorTemplates);
  });

  function PivotTableWrapper(b, c, a, f, d, h, e) {
    this.$containerElem = b;
    this.$t = c;
    this.fixedByTop = [];
    this.fixedByLeft = [];
    this.smooth = a;
    this.rowHdrEnabled = f;
    this.colHdrEnabled = d;
    this.disableByAreaFactor = h;
    this.useSticky = e;
    "boolean" !== typeof e && (b = document.createElement("div"),
      b.style.position = "sticky",
      this.useSticky = 0 <= b.style.position.indexOf("sticky"));
    this.init()
  }
  var g = jQuery;

  PivotTableWrapper.prototype.buildFixedHeaders = function (b) {
    function c(a) {
      return {
        height: a.clientHeight,
        width: a.clientWidth,
        top: a.offsetTop,
        left: a.offsetLeft
      }
    }
    function a(a) {
      a = a.getBoundingClientRect();
      return {
        height: a.height,
        width: a.width,
        top: a.top,
        left: a.left
      }
    }
    var f = this.$containerElem
      , d = this.$t
      , h = []
      , e = this.fixedByTop = []
      , g = this.fixedByLeft = []
      , n = this.rowHdrEnabled
      , t = this.colHdrEnabled;
    f.addClass("pvtFixedHeaderOuterContainer");
    d.addClass("pvtFixedHeader");
    0 < d.find("th.pvtTotalLabel").length && d.addClass("pvtHasTotalsLastColumn");
    for (var u = d[0].getElementsByTagName("TH"), k = 0; k < u.length; k++) {
      var m = u[k]
        , l = 0 <= m.className.indexOf("pvtAxisLabel")
        , q = 0 <= m.className.indexOf("pvtTotalLabel")
        , r = !l && (0 <= m.className.indexOf("pvtColLabel") || q && 0 < k && 0 <= u[k - 1].className.indexOf("pvtColLabel"));
      q = !l && (0 <= m.className.indexOf("pvtRowLabel") || q && 0 < k && 0 <= u[k - 1].className.indexOf("pvtRowLabel"));
      l = {
        th: m,
        isCol: r,
        isRow: q
      };
      r || (l.fixedLeft = !0);
      q || (l.fixedTop = !0);
      r = null;
      if (1 == m.childNodes.length && "DIV" == m.childNodes[0].tagName)
        r = m.childNodes[0],
          r.className = "pvtFixedHeader";
      else {
        r = document.createElement("div");
        r.className = "pvtFixedHeader";
        (l.isCol || l.isRow) && r.setAttribute("title", m.textContent);
        if (0 < m.childNodes.length)
          for (; 0 < m.childNodes.length;)
            r.appendChild(m.childNodes[0]);
        else
          r.textContent = m.textContent;
        m.appendChild(r)
      }
      l.el = r;
      h.push(l)
    }
    u = f[0].getBoundingClientRect ? a : c;
    if (this.useSticky) {
      e = u(d[0]);
      for (k = h.length - 1; 0 <= k; k--)
        l = h[k],
          d = u(l.th),
          l.offsetTop = d.top - e.top,
          l.offsetLeft = d.left - e.left,
          l.width = d.width,
          l.height = d.height;
      k = function () {
        for (var a = 0; a < h.length; a++) {
          var b = h[a];
          b.el.style.height = b.height + "px";
          b.el.style.width = b.width + "px";
          b.el.setAttribute("origin-height", b.el.style.height);
          t && b.fixedTop && (b.th.style.top = b.offsetTop + "px");
          n && b.fixedLeft && (b.th.style.left = b.offsetLeft + "px")
        }
        f.addClass("pvtStickyFixedHeader");
        -1 !== navigator.userAgent.indexOf("Chrome") && f.addClass("pvtStickyChromeFixedHeader")
      }
        ;
      window.requestAnimationFrame && !b ? window.requestAnimationFrame(k) : k()
    } else {
      for (k = h.length - 1; 0 <= k; k--)
        l = h[k],
          d = u(l.th),
          l.height = d.height,
          t && l.fixedTop && e.push({
            el: l.el,
            th: l.th,
            top: 0,
            lastTop: 0
          }),
          n && l.fixedLeft && g.push({
            el: l.el,
            th: l.th,
            left: 0,
            lastLeft: 0
          });
      k = function () {
        for (var a = 0; a < h.length; a++) {
          var b = h[a];
          b.el.style.height = b.height + "px"
        }
      }
        ;
      window.requestAnimationFrame && !b ? window.requestAnimationFrame(k) : k()
    }
  };

  PivotTableWrapper.prototype.refreshHeaders = function (b, c) {
    var a = this.fixedByLeft
      , f = this.fixedByTop
      , d = function () {
        for (var d, e, g = 0; g < a.length; g++)
          e = a[g],
            d = c + e.left,
            d != e.lastLeft && (e.lastLeft = d,
              e.el.style.left = d + "px");
        for (g = 0; g < f.length; g++)
          e = f[g],
            d = b + e.top,
            d != e.lastTop && (e.lastTop = d,
              e.el.style.top = d + "px")
      };
    window.requestAnimationFrame ? window.requestAnimationFrame(d) : d()
  };

  PivotTableWrapper.prototype.destroy = function () {
    this.$containerElem.off("scroll wheel");
    this.resizeHandler && g(window).off("resize", this.resizeHandler);
    this.$t = this.$containerElem = this.fixedByLeft = this.fixedByTop = null
  };

  PivotTableWrapper.prototype.refresh = function () {
    var b = this;
    b.$t.find("div.pvtFixedHeader").each(function () {
      this.style.height = "auto";
      b.useSticky || (this.style.top = "0px",
        this.style.left = "0px")
    });
    b.$containerElem.removeClass("pvtStickyFixedHeader");
    b.buildFixedHeaders(!0);
    this.useSticky || b.refreshHeaders(b.$containerElem[0].scrollTop, b.$containerElem[0].scrollLeft)
  };

  PivotTableWrapper.prototype.init = function () {
    this.buildFixedHeaders();
    var b = this;
    if (!this.useSticky) {
      var c = this.$containerElem[0]
        , a = null
        , f = -1
        , d = -1
        , h = this.smooth ? b.refreshHeaders : function (c, d) {
          a && clearTimeout(a);
          this.$containerElem.addClass("pvtFixedHeadersOutdated");
          a = setTimeout(function () {
            a = null;
            b.$containerElem.removeClass("pvtFixedHeadersOutdated");
            b.refreshHeaders(c, d)
          }, 300)
        }
        ;
      this.$containerElem.on("scroll", function (a) {
        a = c.scrollTop;
        var e = c.scrollLeft;
        if (a != f || e != d)
          f = a,
            d = e,
            h.call(b, a, e)
      });
      this.$containerElem.scroll()
    }
    var e = this.$containerElem[0].clientWidth;
    this.resizeHandler = function () {
      var a = b.$containerElem[0].clientWidth;
      e != a && (e = a,
        a = function () {
          b.refresh()
        }
        ,
        window.requestAnimationFrame ? window.requestAnimationFrame(a) : a())
    }
      ;
    g(window).on("resize", this.resizeHandler)
  };

  window.PivotTableExtensions = function (b) {
    this.options = g.extend({}, PivotTableExtensions.defaults, b)
  };

  window.PivotTableExtensions.prototype.initFixedHeaders = function (b, c, a) {
    0 != b.length && (c = c ? b.closest(".pvtFixedHeaderOuterContainer") : b.parent(),
      a = "object" === typeof a ? a : {},
      this.fixedHeaders && this.fixedHeaders.destroy(),
      // this.fixedHeaders = new PivotTableWrapper(c, b, !0 === a.smooth ? !0 : !1, !1 === a.rows ? !1 : !0, !1 === a.columns ? !1 : !0, a.disableByAreaFactor ? a.disableByAreaFactor : .5, !1 === a.useSticky ? !1 : !0))

      this.fixedHeaders = new PivotTableWrapper(c, b, !0 === a.smooth ? !0 : !1, !1 === a.rows ? !1 : !0, !1 === a.columns ? !1 : !0, a.disableByAreaFactor ? a.disableByAreaFactor : .5, !1 === a.useSticky ? !1 : !0));


      setTimeout(function(){
        jQuery("th[root-node='1']:first").click();
      }, 1);
  };

  window.PivotTableExtensions.defaults = {
    drillDownHandler: null,
    wrapWith: null,
    onSortHandler: function (b) { },
    sortByLabelEnabled: !0,
    sortByColumnsEnabled: !0,
    sortByRowsEnabled: !0,
    fixedHeaders: !1
  }

}).call(this);

//# sourceMappingURL=subtotal.js.map
