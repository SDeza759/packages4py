Introduction
================================================================================

This section introduces Excel data models, its representing data structures and
provides an overview of formatting, transformation, manipulation supported by
**pyexcel**.

Data models and data structures
--------------------------------
When dealing with excel files, **pyexcel** pay attention to three primary
objects: **cell**, **sheet** and **book**.

A book contains one or more sheets and a sheet is consisted of a sheet name and
a two dimensional array of cells. Although a sheet can contain charts and a cell
can have formula, styling properties, this library ignores them and only pays
attention to the data in the cell and its data type. So, in the context of this
library, the definition of those three concepts are:

========= ======================================================== =======================
concept   definition                                               pyexcel data model
========= ======================================================== =======================
a cell    is a data unit                                           a Python data type
a sheet   is a named two dimensional array of data units           :class:`~pyexcel.Sheet`
a book    is a dictionary of two dimensional array of data units.  :class:`~pyexcel.Book`
========= ======================================================== =======================

Data source
--------------------------------------------------------------------------------

A data source is a storage format of structured data. The most popular data
source is an excel file. Libre Office/Microsoft Excel can easily be used to generate an 
excel file of your desired format. Besides a physical file, this library
recognizes three additional types of source:

#. Excel files in computer memory. For example: when a file is uploaded to
   a Python server for information processing. If it is relatively small,
   it can be stored in memory.
#. Database tables. For example: a client would like to have a snapshot of some
   database table in an excel file and asks it to be sent to him.
#. Python structures. For example: a developer may have scraped a site and have
   stored data in Python array or dictionary. He may want to save this
   information as a file.


Reading from - and writing to - a data source is modelled as parsers and renderers
in pyexcel. Excel data sources and database sources support read and write. Other
data sources may only support read only, or write only methods.

Here is a list of data sources:

========================== ===========================
Data source                Read and write properties
========================== ===========================
Array                      Read and write
Dictionary                 Same as above
Records                    Same as above
Excel files                Same as above
Excel files in memory      Same as above
Excel files on the web     Read only
Django models              Read and write
SQL models                 Read and write
Database querysets         Read only
Textual sources            Write only
========================== ===========================


Data format
--------------------------------------------------------------------------------

This library and its plugins support most of the frequently used excel file
formats. 

============ =======================================================
file format  definition
============ =======================================================
csv          comma separated values
tsv          tab separated values
csvz         a zip file that contains one or many csv files
tsvz         a zip file that contains one or many tsv files
xls          a spreadsheet file format created by
             MS-Excel 97-2003 [#f1]_
xlsx         MS-Excel Extensions to the Office Open XML
             SpreadsheetML File Format. [#f2]_
xlsm         an MS-Excel Macro-Enabled Workbook file
ods          open document spreadsheet
json         java script object notation
html         html table of the data structure
simple       `simple` presentation
rst          rStructured Text presentation of the data
mediawiki    media wiki table
============ =======================================================

See also :ref:`a-map-of-plugins-and-file-formats`.

Data transformation
--------------------------------------------------------------------------------

Often a developer would like to have excel data imported into a Python data
structure. This library supports the :ref:`conversions from<conversion-from>`
previous three data source to the following list of data structures, and
:ref:`vice versa<conversion-to>`.

.. _a-list-of-data-structures:
.. table:: A list of supported data structures

   ======================================= ================================ =========================
   Pesudo name                             Python name                      Related model
   ======================================= ================================ =========================
   two dimensional array                   a list of lists                  :class:`pyexcel.Sheet`
   a dictionary of key value pair          a dictionary                     :class:`pyexcel.Sheet`
   a dictionary of one dimensional arrays  a dictionary of lists            :class:`pyexcel.Sheet`
   a list of dictionaries                  a list of dictionaries           :class:`pyexcel.Sheet`
   a dictionary of two dimensional arrays  a dictionary of lists of lists   :class:`pyexcel.Book`
   ======================================= ================================ =========================


Data manipulation
--------------------------------------------------------------------------------

The main operation on a cell involves :ref:`cell access<access-to-cell>`,
:ref:`formatting<formatting>` and :ref:`cleansing<cleansing>`. The main
operation on a sheet involves group access to a row or a column; data
filtering; and data transformation. The main operation in a book is obtain access
to individual sheets.


Data transcoding
--------------------------------------------------------------------------------

For various reasons the data in one format needs to be transcoded into another.
This library provides a transcoding tunnel for data transcoding 
between supported file formats.

Data visualization
--------------------------------------------------------------------------------

Via :class:`pyexel.renderer.AbstractRenderer` interface, data visualization
is made possible. **pyexcel-chart** is the interface plugin to formalize this
effort. **pyexcel-pygal** is the first plugin to provide bar, pie, histogram
charts and more.

Examples of supported data structure
--------------------------------------------------------------------------------

Here is a list of examples::

    >>> import pyexcel as p
    >>> two_dimensional_list = [
    ...    [1, 2, 3, 4],
    ...    [5, 6, 7, 8],
    ...    [9, 10, 11, 12],
    ... ]
    >>> p.get_sheet(array=two_dimensional_list)
    pyexcel_sheet1:
    +---+----+----+----+
    | 1 | 2  | 3  | 4  |
    +---+----+----+----+
    | 5 | 6  | 7  | 8  |
    +---+----+----+----+
    | 9 | 10 | 11 | 12 |
    +---+----+----+----+
    >>> a_dictionary_of_key_value_pair = {
    ...    "IE": 0.2,
    ...    "Firefox": 0.3
    ... }
    >>> p.get_sheet(adict=a_dictionary_of_key_value_pair)
    pyexcel_sheet1:
    +---------+-----+
    | Firefox | IE  |
    +---------+-----+
    | 0.3     | 0.2 |
    +---------+-----+
    >>> a_dictionary_of_one_dimensional_arrays = {
    ...     "Column 1": [1, 2, 3, 4],
    ...     "Column 2": [5, 6, 7, 8],
    ...     "Column 3": [9, 10, 11, 12],
    ... }
    >>> p.get_sheet(adict=a_dictionary_of_one_dimensional_arrays)
    pyexcel_sheet1:
    +----------+----------+----------+
    | Column 1 | Column 2 | Column 3 |
    +----------+----------+----------+
    | 1        | 5        | 9        |
    +----------+----------+----------+
    | 2        | 6        | 10       |
    +----------+----------+----------+
    | 3        | 7        | 11       |
    +----------+----------+----------+
    | 4        | 8        | 12       |
    +----------+----------+----------+
    >>> a_list_of_dictionaries = [
    ...     {
    ...         "Name": 'Adam',
    ...         "Age": 28
    ...     },
    ...     {
    ...         "Name": 'Beatrice',
    ...         "Age": 29
    ...     },
    ...     {
    ...         "Name": 'Ceri',
    ...         "Age": 30
    ...     },
    ...     {
    ...         "Name": 'Dean',
    ...         "Age": 26
    ...     }
    ... ]
    >>> p.get_sheet(records=a_list_of_dictionaries)
    pyexcel_sheet1:
    +-----+----------+
    | Age | Name     |
    +-----+----------+
    | 28  | Adam     |
    +-----+----------+
    | 29  | Beatrice |
    +-----+----------+
    | 30  | Ceri     |
    +-----+----------+
    | 26  | Dean     |
    +-----+----------+
    >>> a_dictionary_of_two_dimensional_arrays = {
    ...      'Sheet 1':
    ...          [
    ...              [1.0, 2.0, 3.0],
    ...              [4.0, 5.0, 6.0],
    ...              [7.0, 8.0, 9.0]
    ...          ],
    ...      'Sheet 2':
    ...          [
    ...              ['X', 'Y', 'Z'],
    ...              [1.0, 2.0, 3.0],
    ...              [4.0, 5.0, 6.0]
    ...          ],
    ...      'Sheet 3':
    ...          [
    ...              ['O', 'P', 'Q'],
    ...              [3.0, 2.0, 1.0],
    ...              [4.0, 3.0, 2.0]
    ...          ]
    ...  }
    >>> p.get_book(bookdict=a_dictionary_of_two_dimensional_arrays)
    Sheet 1:
    +-----+-----+-----+
    | 1.0 | 2.0 | 3.0 |
    +-----+-----+-----+
    | 4.0 | 5.0 | 6.0 |
    +-----+-----+-----+
    | 7.0 | 8.0 | 9.0 |
    +-----+-----+-----+
    Sheet 2:
    +-----+-----+-----+
    | X   | Y   | Z   |
    +-----+-----+-----+
    | 1.0 | 2.0 | 3.0 |
    +-----+-----+-----+
    | 4.0 | 5.0 | 6.0 |
    +-----+-----+-----+
    Sheet 3:
    +-----+-----+-----+
    | O   | P   | Q   |
    +-----+-----+-----+
    | 3.0 | 2.0 | 1.0 |
    +-----+-----+-----+
    | 4.0 | 3.0 | 2.0 |
    +-----+-----+-----+


.. [#f1] quoted from `whatis.com <http://whatis.techtarget.com/fileformat/XLS-Worksheet-file-Microsoft-Excel>`_. Technical details can be found at `MSDN XLS <https://msdn.microsoft.com/en-us/library/office/gg615597(v=office.14).aspx>`_
.. [#f2] xlsx is used by MS-Excel 2007, more information can be found at `MSDN XLSX <https://msdn.microsoft.com/en-us/library/dd922181(v=office.12).aspx>`_
