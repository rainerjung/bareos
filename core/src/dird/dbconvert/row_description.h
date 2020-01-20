/*
   BAREOS® - Backup Archiving REcovery Open Sourced

   Copyright (C) 2000-2012 Free Software Foundation Europe e.V.
   Copyright (C) 2011-2016 Planets Communications B.V.
   Copyright (C) 2020-2020 Bareos GmbH & Co. KG

   This program is Free Software; you can redistribute it and/or
   modify it under the terms of version three of the GNU Affero General Public
   License as published by the Free Software Foundation and included
   in the file LICENSE.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.
*/

#ifndef BAREOS_SRC_DIRD_DBCONVERT_ROW_DESCRIPTION_H_
#define BAREOS_SRC_DIRD_DBCONVERT_ROW_DESCRIPTION_H_

#include <functional>
#include <map>
#include <string>

class RowDescription {
 public:
  RowDescription(const char* column_name_in,
                 const char* data_type_in,
                 const char* max_length_in);

  std::string column_name;
  std::string data_type;
  std::size_t character_maximum_length{};
  std::function<const char*(const char*)> db_export_converter;
  std::function<const char*(const char*)> db_import_converter;
};

class RowDescriptionMysql : public RowDescription {
 public:
  RowDescriptionMysql(const char* column_name_in,
                      const char* data_type_in,
                      const char* max_length_in);
  static const std::map<std::string, std::function<const char*(const char*)>>
      data_type_converter;
};

class RowDescriptionPostgresql : public RowDescription {
 public:
  RowDescriptionPostgresql(const char* column_name_in,
                           const char* data_type_in,
                           const char* max_length_in);
  static const std::map<std::string, std::function<const char*(const char*)>>
      data_type_converter;
};


#endif  // BAREOS_SRC_DIRD_DBCONVERT_ROW_DESCRIPTION_H_