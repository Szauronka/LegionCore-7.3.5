/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Resolver_h__
#define Resolver_h__

#include "Common.h"
#include "Optional.h"
#include <boost/asio/ip/tcp.hpp>

namespace Trinity
{
    namespace Asio
    {
        /**
          Hack to make it possible to forward declare resolver (one of its template arguments is a typedef to something super long and using nested classes)
        */
        class Resolver
        {
        public:
#if BOOST_VERSION >= 106600
            explicit Resolver(boost::asio::io_context& ioContext) : _impl(ioContext) {}
#else
            explicit Resolver(boost::asio::io_service& ioService) : _impl(ioService) {}
#endif

            Optional<boost::asio::ip::tcp::endpoint> Resolve(boost::asio::ip::tcp const& protocol, std::string const& host, std::string const& service)
            {
                boost::system::error_code ec;
                boost::asio::ip::resolver_query_base::flags flagsResolver = boost::asio::ip::resolver_query_base::all_matching;
                boost::asio::ip::tcp::resolver::query externalAddressQuery(protocol, host, service, flagsResolver);

                boost::asio::ip::tcp::resolver::iterator end;
                boost::asio::ip::tcp::resolver::iterator results = _impl.resolve(externalAddressQuery, ec);
                if (results == end || ec)
                    return {};

                return results->endpoint();
            }

        private:
            boost::asio::ip::tcp::resolver _impl;
        };
    }
}

#endif // Resolver_h__