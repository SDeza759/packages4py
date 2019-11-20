One liners
================================================================================

This section shows you how to get data from your excel files and how to
export data to excel files in **one line**

One liner to get data from the excel files
--------------------------------------------------------------------------------

Get a list of dictionaries
********************************************************************************

.. testcode::
   :hide:

   >>> import os
   >>> import pyexcel as p
   >>> content="""
   ... Coffees,Serving Size,Caffeine (mg)
   ... Starbucks Coffee Blonde Roast,venti(20 oz),475
   ... Dunkin' Donuts Coffee with Turbo Shot,large(20 oz.),398
   ... Starbucks Coffee Pike Place Roast,grande(16 oz.),310
   ... Panera Coffee Light Roast,regular(16 oz.),300
   ... """.strip()
   >>> sheet = p.get_sheet(file_content=content, file_type='csv')
   >>> sheet.save_as("your_file.xls")

Suppose you want to process the :download:`following coffee data <coffee.csv>` (data source `coffee chart <https://cspinet.org/eating-healthy/ingredients-of-concern/caffeine-chart>`_ on the center for science in the public interest):

.. pyexcel-table::

   ---pyexcel:Top 5 coffeine drinks---
   Coffees,Serving Size,Caffeine (mg)
   Starbucks Coffee Blonde Roast,venti(20 oz),475
   Dunkin' Donuts Coffee with Turbo Shot,large(20 oz.),398
   Starbucks Coffee Pike Place Roast,grande(16 oz.),310
   Panera Coffee Light Roast,regular(16 oz.),300

Let's get a list of dictionary out from the xls file::
   
   >>> records = p.get_records(file_name="your_file.xls")

And let's check what do we have::

   >>> for record in records:
   ...     print("%s of %s has %s mg" % (
   ...         record['Serving Size'],
   ...         record['Coffees'],
   ...         record['Caffeine (mg)']))
   venti(20 oz) of Starbucks Coffee Blonde Roast has 475 mg
   large(20 oz.) of Dunkin' Donuts Coffee with Turbo Shot has 398 mg
   grande(16 oz.) of Starbucks Coffee Pike Place Roast has 310 mg
   regular(16 oz.) of Panera Coffee Light Roast has 300 mg


Get two dimensional array
********************************************************************************

Instead, what if you have to use :meth:`pyexcel.get_array` to do the same:

   >>> for row in p.get_array(file_name="your_file.xls", start_row=1):
   ...     print("%s of %s has %s mg" % (
   ...         row[1],
   ...         row[0],
   ...         row[2]))
   venti(20 oz) of Starbucks Coffee Blonde Roast has 475 mg
   large(20 oz.) of Dunkin' Donuts Coffee with Turbo Shot has 398 mg
   grande(16 oz.) of Starbucks Coffee Pike Place Roast has 310 mg
   regular(16 oz.) of Panera Coffee Light Roast has 300 mg

where `start_row` skips the header row.


Get a dictionary
********************************************************************************

You can get a dictionary too:

Now let's get a dictionary out from the spreadsheet:

.. code-block:: python
    
   >>> my_dict = p.get_dict(file_name="your_file.xls", name_columns_by_row=0)

And check what do we have::

   >>> from pyexcel._compact import OrderedDict
   >>> isinstance(my_dict, OrderedDict)
   True
   >>> for key, values in my_dict.items():
   ...     print(key + " : " + ','.join([str(item) for item in values]))
   Coffees : Starbucks Coffee Blonde Roast,Dunkin' Donuts Coffee with Turbo Shot,Starbucks Coffee Pike Place Roast,Panera Coffee Light Roast
   Serving Size : venti(20 oz),large(20 oz.),grande(16 oz.),regular(16 oz.)
   Caffeine (mg) : 475,398,310,300

Please note that my_dict is an OrderedDict.

Get a dictionary of two dimensional array
********************************************************************************

.. testcode::
   :hide:

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
   >>> data = OrderedDict()
   >>> data.update({"Sheet 1": a_dictionary_of_two_dimensional_arrays['Sheet 1']})
   >>> data.update({"Sheet 2": a_dictionary_of_two_dimensional_arrays['Sheet 2']})
   >>> data.update({"Sheet 3": a_dictionary_of_two_dimensional_arrays['Sheet 3']})
   >>> p.save_book_as(bookdict=data, dest_file_name="book.xls")

Suppose you have a multiple sheet book as the following:

.. pyexcel-table::

   ---pyexcel:Sheet 1---
   1,2,3
   4,5,6
   7,8,9
   ---pyexcel---
   ---pyexcel:Sheet 2---
   X,Y,Z
   1,2,3
   4,5,6
   ---pyexcel---
   ---pyexcel:Sheet 3---
   O,P,Q
   3,2,1
   4,3,2

Here is the code to obtain those sheets as a single dictionary::

   >>> book_dict = p.get_book_dict(file_name="book.xls")

And check::
   >>> isinstance(book_dict, OrderedDict)
   True
   >>> import json
   >>> for key, item in book_dict.items():
   ...     print(json.dumps({key: item}))
   {"Sheet 1": [[1, 2, 3], [4, 5, 6], [7, 8, 9]]}
   {"Sheet 2": [["X", "Y", "Z"], [1, 2, 3], [4, 5, 6]]}
   {"Sheet 3": [["O", "P", "Q"], [3, 2, 1], [4, 3, 2]]}

.. testcode::
   :hide:

   >>> import os
   >>> os.unlink("book.xls")


Data export in one line
---------------------------------------------

Export an array
**********************

Suppose you have the following array::

   >>> data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

And here is the code to save it as an excel file ::

   >>> p.save_as(array=data, dest_file_name="example.xls")

Let's verify it::

    >>> p.get_sheet(file_name="example.xls")
    pyexcel_sheet1:
    +---+---+---+
    | 1 | 2 | 3 |
    +---+---+---+
    | 4 | 5 | 6 |
    +---+---+---+
    | 7 | 8 | 9 |
    +---+---+---+

.. testcode::
   :hide:

   >>> import os
   >>> os.unlink("example.xls")


And here is the code to save it as a csv file ::

   >>> p.save_as(array=data,
   ...           dest_file_name="example.csv",
   ...           dest_delimiter=':')

Let's verify it::

   >>> with open("example.csv") as f:
   ...     for line in f.readlines():
   ...         print(line.rstrip())
   ...
   1:2:3
   4:5:6
   7:8:9

Export a list of dictionaries
**********************************

::

    >>> records = [
    ...     {"year": 1903, "country": "Germany", "speed": "206.7km/h"},
    ...     {"year": 1964, "country": "Japan", "speed": "210km/h"},
    ...     {"year": 2008, "country": "China", "speed": "350km/h"}
    ... ]
    >>> p.save_as(records=records, dest_file_name='high_speed_rail.xls')


Export a dictionary of single key value pair
********************************************************************************

::

    >>> henley_on_thames_facts = {
    ...     "area": "5.58 square meters",
    ...     "population": "11,619",
    ...     "civial parish": "Henley-on-Thames",
    ...     "latitude": "51.536",
    ...     "longitude": "-0.898"
    ... }
    >>> p.save_as(adict=henley_on_thames_facts, dest_file_name='henley.xlsx')


Export a dictionary of single dimensonal array
********************************************************************************

    >>> ccs_insights = {
    ...     "year": ["2017", "2018", "2019", "2020", "2021"],
    ...     "smart phones": [1.53, 1.64, 1.74, 1.82, 1.90],
    ...     "feature phones": [0.46, 0.38, 0.30, 0.23, 0.17]
    ... }
    >>> p.save_as(adict=ccs_insights, dest_file_name='ccs.csv')


Export a dictionary of two dimensional array as a book
********************************************************************************

Suppose you want to save the below dictionary to an excel file ::
  
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

Here is the code::

   >>> p.save_book_as(
   ...    bookdict=a_dictionary_of_two_dimensional_arrays,
   ...    dest_file_name="book.xls"
   ... )

If you want to preserve the order of sheets in your dictionary, you have to
pass on an ordered dictionary to the function itself. For example::

   >>> data = OrderedDict()
   >>> data.update({"Sheet 2": a_dictionary_of_two_dimensional_arrays['Sheet 2']})
   >>> data.update({"Sheet 1": a_dictionary_of_two_dimensional_arrays['Sheet 1']})
   >>> data.update({"Sheet 3": a_dictionary_of_two_dimensional_arrays['Sheet 3']})
   >>> p.save_book_as(bookdict=data, dest_file_name="book.xls")

Let's verify its order::

   >>> book_dict = p.get_book_dict(file_name="book.xls")
   >>> for key, item in book_dict.items():
   ...     print(json.dumps({key: item}))
   {"Sheet 2": [["X", "Y", "Z"], [1, 2, 3], [4, 5, 6]]}
   {"Sheet 1": [[1, 2, 3], [4, 5, 6], [7, 8, 9]]}
   {"Sheet 3": [["O", "P", "Q"], [3, 2, 1], [4, 3, 2]]}

Please notice that "Sheet 2" is the first item in the *book_dict*, meaning the order of sheets are preserved.


File format transcoding on one line
-------------------------------------------

.. note::

   Please note that the following file transcoding could be with zero line. Please
   install pyexcel-cli and you will do the transcode in one command. No need to
   open your editor, save the problem, then python run.


.. testcode::
   :hide:

   >>> import datetime
   >>> data = [
   ...    ["name", "weight", "birth"],
   ...    ["Adam", 3.4, datetime.date(2015, 2, 3)],
   ...    ["Smith", 4.2, datetime.date(2014, 11, 12)]
   ... ]
   >>> p.save_as(array=data, dest_file_name="birth.xls")

The following code does a simple file format transcoding from xls to csv::

   >>> p.save_as(file_name="birth.xls", dest_file_name="birth.csv")

Again it is really simple. Let's verify what we have gotten:

   >>> sheet = p.get_sheet(file_name="birth.csv")
   >>> sheet
   birth.csv:
   +-------+--------+----------+
   | name  | weight | birth    |
   +-------+--------+----------+
   | Adam  | 3.4    | 03/02/15 |
   +-------+--------+----------+
   | Smith | 4.2    | 12/11/14 |
   +-------+--------+----------+

.. NOTE::

   Please note that csv(comma separate value) file is pure text file. Formula, charts, images and formatting in xls file will disappear no matter which transcoding tool you use. Hence, pyexcel is a quick alternative for this transcoding job.


Let use previous example and save it as xlsx instead

   >>> p.save_as(file_name="birth.xls",
   ...           dest_file_name="birth.xlsx") # change the file extension

Again let's verify what we have gotten:

   >>> sheet = p.get_sheet(file_name="birth.xlsx")
   >>> sheet
   pyexcel_sheet1:
   +-------+--------+----------+
   | name  | weight | birth    |
   +-------+--------+----------+
   | Adam  | 3.4    | 03/02/15 |
   +-------+--------+----------+
   | Smith | 4.2    | 12/11/14 |
   +-------+--------+----------+


Excel book merge and split operation in one line
--------------------------------------------------------------------------------

Merge all excel files in directory into  a book where each file become a sheet
********************************************************************************

The following code will merge every excel files into one file, say "output.xls"::

    from pyexcel.cookbook import merge_all_to_a_book
    import glob


    merge_all_to_a_book(glob.glob("your_csv_directory\*.csv"), "output.xls")

You can mix and match with other excel formats: xls, xlsm and ods. For example, if you are sure you have only xls, xlsm, xlsx, ods and csv files in `your_excel_file_directory`, you can do the following::

    from pyexcel.cookbook import merge_all_to_a_book
    import glob


    merge_all_to_a_book(glob.glob("your_excel_file_directory\*.*"), "output.xls")

Split a book into single sheet files
****************************************

.. testcode::
   :hide:

    >>> content = {
    ...     'Sheet 1': 
    ...         [
    ...             [1.0, 2.0, 3.0], 
    ...             [4.0, 5.0, 6.0], 
    ...             [7.0, 8.0, 9.0]
    ...         ],
    ...     'Sheet 2': 
    ...         [
    ...             ['X', 'Y', 'Z'], 
    ...             [1.0, 2.0, 3.0], 
    ...             [4.0, 5.0, 6.0]
    ...         ], 
    ...     'Sheet 3': 
    ...         [
    ...             ['O', 'P', 'Q'], 
    ...             [3.0, 2.0, 1.0], 
    ...             [4.0, 3.0, 2.0]
    ...         ] 
    ... }
    >>> book = p.Book(content)
    >>> book.save_as("megabook.xls")

Suppose you have many sheets in a work book and you would like to separate each into a single sheet excel file. You can easily do this::

   >>> from pyexcel.cookbook import split_a_book
   >>> split_a_book("megabook.xls", "output.xls")
   >>> import glob
   >>> outputfiles = glob.glob("*_output.xls")
   >>> for file in sorted(outputfiles):
   ...     print(file)
   ...
   Sheet 1_output.xls
   Sheet 2_output.xls
   Sheet 3_output.xls

for the output file, you can specify any of the supported formats

.. testcode::
   :hide:

   >>> os.unlink("Sheet 1_output.xls")
   >>> os.unlink("Sheet 2_output.xls")
   >>> os.unlink("Sheet 3_output.xls")

Extract just one sheet from a book
*************************************


Suppose you just want to extract one sheet from many sheets that exists in a work book and you would like to separate it into a single sheet excel file. You can easily do this::

    >>> from pyexcel.cookbook import extract_a_sheet_from_a_book
    >>> extract_a_sheet_from_a_book("megabook.xls", "Sheet 1", "output.xls")
    >>> if os.path.exists("Sheet 1_output.xls"):
    ...     print("Sheet 1_output.xls exists")
    ...
    Sheet 1_output.xls exists

for the output file, you can specify any of the supported formats

.. testcode::
   :hide:

   >>> os.unlink("Sheet 1_output.xls")
   >>> os.unlink("megabook.xls")
   >>> os.unlink('birth.xls')
   >>> os.unlink('birth.csv')
   >>> os.unlink('birth.xlsx')
   >>> os.unlink('high_speed_rail.xls')
   >>> os.unlink('henley.xlsx')
   >>> os.unlink('ccs.csv')
   >>> os.unlink("book.xls")
   >>> os.unlink("your_file.xls")
   >>> os.unlink("example.csv")
