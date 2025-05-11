# Modular Weapon Attachments plugin

## v 0.1
- Create new _DataTable_, derived from `FAttachmetnModuleData` structure.
- Inside weapon class, add Weapon Attachments Manager (`UWeaponAttachmetnsManager`) actor component.
- On weapon constructor, make sure to call `SetBaseWeaponMeshComponent` from attachmetns manager component. 

- **WeaponAttachmentsManager**
    - Actor component, that can be added to the weapon class. Both in c++ and BP
    - `Install attachment`: install selected attachment to required slot. `SlotName` - required slot. `Module data` - new attachment module data (struct). 
    - `RemoveModule`: removes module from required slot (param `SlotName`).
    - `GetActiveSlots`: currently used slots on the current weapon, includes from child modules.
    - `GetActiveAttachments`: currently used attachments, include childs.
    - `GetCompatibleAttachments`: get all attachmetns, compatible with this weapon.
    - `GetCompatibleAttachmetnsByType`: get compatible attachments for this weapon, with specific selected type.

    *Properties:*
    - `AttachmentsTable`: reference to DataTable with attachments. 
    - `Attachment slots`: default weapon slots. Persistant and destroyable.
    - `Compatible attachments`: list of all compatible attachments for this weapon. Use row names from `AttachmentsTable`.

- **Attachment slots:**
    - `SlotName` - slot display name. Make sure it's unique, since also it uses to asses to slots.
    - `SocketName` - socket name from the weapon or attachment mesh. Defines slot location and where new module needs to be attached. *_Make sure its the same name as socket name on the mesh_*.
    - `SlotType` - defines attachment types that can be installed in this slot. 
- **AttachmentModuleData:**
    - `Display name`: display name for this module. Currently used for UI.
    - `Mesh`: attachment static mesh. Maybe add skeletal mesh in future.
    - `ModuleType`: tupe of attachment module. Used in collaboration with attachment slots.
    - `Child slots`: child slots list. Make sure attachment mesh has properly named required slots. This slots adds to total list of current weapon slots.