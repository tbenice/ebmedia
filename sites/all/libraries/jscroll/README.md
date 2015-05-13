# jScroll jQuery Plugin for Infinite Scrolling / Auto-Paging

Official site at [jscroll.com](http://jscroll.com/).

* Copyright (C) 2011-2013, [Philip Klauzinski](http://klauzinski.com/)
* Current Version: 2.1.1
* Dual licensed under the MIT and GPL Version 2 licenses.
* http://jscroll.com/#license
* http://www.opensource.org/licenses/mit-license.php
* http://www.gnu.org/licenses/gpl-2.0.html

Requires jQuery v1.4.3+

## Usage

The `jscroll` method is called on the selector for which you want your scrollable content contained within. For example:

```javascript
$('.jscroll').jscroll();
```

The `jscroll` method takes an optional object literal as a parameter for overriding the default options. An example of how this can be done is shown below.

```javascript
$('.jscroll').jscroll({
    loadingHtml: '<img src="loading.gif" alt="Loading" /> Loading...',
    padding: 20,
    nextSelector: 'a.jscroll-next:last',
    contentSelector: 'li'
});
```

## Options

* debug           (false)  When set to true, outputs useful information to the console display if the console object exists.
* autoTrigger     (true)  When set to true, triggers the loading of the next set of content automatically when the user scrolls to the bottom of the containing element. When set to false, the required next link will trigger the loading of the next set of content when clicked.
* loadingHtml     (`'<small>Loading...</small>'`)  The HTML to show at the bottom of the content while loading the next set.
* padding         (0)  The distance from the bottom of the scrollable content at which to trigger the loading of the next set of content. This only applies when autoTrigger is set to true.
* nextSelector    ('a:last')  The selector to use for finding the link which contains the href pointing to the next set of content. If this selector is not found, or if it does not contain a href attribute, jScroll will self-destroy and unbind from the element upon which it was called.
* contentSelector ('')  A convenience selector for loading only part of the content in the response for the next set of content. This selector will be ignored if left blank and will apply the entire response to the DOM.
* pagingSelector  ('')  Optionally define a selector for your paging controls so that they will be hidden, instead of just hiding the next page link.

For more information on the *contentSelector* option and how it loads a response fragment, see the [jQuery documentation for the .load() method](http://api.jquery.com/load/).

## MIT LICENSE:

Copyright (C) 2011-2013 by [Philip Klauzinski](http://klauzinski.com/)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.