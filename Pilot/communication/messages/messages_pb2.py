# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: messages.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='messages.proto',
  package='',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=b'\n\x0emessages.proto\"/\n\x0c\x64riveMessage\x12\x10\n\x08steering\x18\x01 \x01(\x05\x12\r\n\x05power\x18\x02 \x01(\x02\x62\x06proto3'
)




_DRIVEMESSAGE = _descriptor.Descriptor(
  name='driveMessage',
  full_name='driveMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='steering', full_name='driveMessage.steering', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='power', full_name='driveMessage.power', index=1,
      number=2, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=18,
  serialized_end=65,
)

DESCRIPTOR.message_types_by_name['driveMessage'] = _DRIVEMESSAGE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

driveMessage = _reflection.GeneratedProtocolMessageType('driveMessage', (_message.Message,), {
  'DESCRIPTOR' : _DRIVEMESSAGE,
  '__module__' : 'messages_pb2'
  # @@protoc_insertion_point(class_scope:driveMessage)
  })
_sym_db.RegisterMessage(driveMessage)


# @@protoc_insertion_point(module_scope)