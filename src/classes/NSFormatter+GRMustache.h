// The MIT License
//
// Copyright (c) 2013 Gwendal Roué
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "GRMustacheRendering.h"
#import "GRMustacheFilter.h"
#import "GRMustacheTagDelegate.h"

/**
 * A category on NSFormatter that allows them to be directly used in GRMustache
 * templates.
 *
 * This applies to all NSFormatter subclasses such as NSDateFormatter,
 * NSNumberFormatter, and your custom subclasses that provide their custom
 * implementation of the `stringForObjectValue:` method.
 *
 * ## Filter facet
 *
 * A formatter can be used as a filter, as in {{ percent(value) }}. Just have
 * your `percent` key evaluate to a formatter.
 *
 * ## Formatting all values in a section
 *
 * A formatter can be used to format all values in a section of a template:
 *
 *     {{# percent }}...{{ value1 }}...{{ value2 }}...{{/ percent }}
 *
 * The formatting applies to all variable tags that evaluate to a value that can
 * be processed by the filter (see [NSFormatter stringForObjectValue:]
 * documentation).
 *
 * Sections are unaffected, in order to preserve loops and boolean sections.
 * However their inner variable tags are:
 *
 *     {{# percent }}
 *       {{ value1 }}        {{! format applies }}
 *       {{# condition }}    {{! format does not apply }}
 *         {{ value2 }}      {{! format applies }}
 *       {{/ condition }}
 *     {{/ percent }}
 */
#warning missing availability macro and @since declaration
@interface NSFormatter (GRMustache)<GRMustacheFilter, GRMustacheRendering, GRMustacheTagDelegate>
@end
